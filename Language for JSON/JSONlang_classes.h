#ifndef JSONLANG_CLASSES_H
#define JSONLANG_CLASSES_H

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <assert.h>

enum json_type {
    string_t, number_t,
    true_t, false_t, null_t,
    array_t, object_t
};

class json;

class rValue {
public:
    json_type type;

    virtual std::string toString() = 0;
    virtual bool isEqualWith(json val) = 0;

    virtual json size_of();
    virtual json is_empty();
    virtual json has_key(std::string key);
    virtual json type_of() = 0;
};

class json {
public:
    rValue * rv;
    std::list<json> harvestedFields; // for json types it's empty
    bool isError = false;

    json();
    json(rValue * rVal);
    json(std::initializer_list<json>);

    friend std::ostream& operator,(std::ostream &output, const json js);
    json operator,(json right);

    json operator[](json js);
    json operator[](int index);
    json operator[](std::string key);
};

class Workable {
public:
    json * jsVal;

    Workable();
    Workable(json js);

    Workable operator,(json right);
    Workable operator<<(json right);
};

class Number : public rValue {
public:
    double value;

    Number(double d);

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json type_of() override;
};

class String : public rValue {
public:
    std::string value;

    String(std::string s);

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json type_of() override;
};

class True : public rValue {
public:
    bool value;

    True();

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json type_of() override;
};

class False : public rValue {
public:
    bool value;

    False();

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json type_of() override;
};

class Null : public rValue {
public:

    Null();

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json type_of() override;
};

class Object : public rValue {
public:

    struct objectElem {
        std::string key;
        json value;
    };

    std::list<objectElem> contents;

    Object();
    Object(std::list<objectElem> l);

    bool insertObject(std::string key, json val);
    bool containsKey(std::string key);

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json size_of() override;
    virtual json is_empty() override;
    virtual json has_key(std::string key) override;
    virtual json type_of() override;
};

class Array : public rValue {
public:
    std::list<json> contents;

    Array();
    Array(std::list<json> l);

    virtual std::string toString() override;
    virtual bool isEqualWith(json val) override;

    virtual json size_of() override;
    virtual json is_empty() override;
    virtual json type_of() override;
};

void errorChecking(json err);

#endif /* JSONLANG_CLASSES_H */

