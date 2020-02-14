#include <iostream>
#include <list>
#include <string> 
#include <assert.h>
#include "JSONlang.h"

using namespace std;

json rValue::size_of() {
    return json(new Number(1));
}

json rValue::is_empty() {
    return json(new False());
}

json rValue::has_key(std::string key) {
    return json(new False());
}

/* JSON */

json::json() {
    rv = new Object();
}

json::json(rValue* rVal) {
    rv = rVal;
}

json::json(std::initializer_list<json> t) {
    std::string key;
    this->rv = new Object();
    if (t.size() != 0) {
        for (auto x : t) {
            if (key.empty()) {
                assert(x.rv->type == string_t);
                key = ((String *) x.rv)->value;
            } else {
                if (((Object *) rv)->insertObject(key, x)) {
                    key.clear();
                } else {
                    cout << "Error: Key already exist" << endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}

std::ostream& operator,(std::ostream &output, const json js) {
    errorChecking(js);
    std::string str = "";

    str.append(js.rv->toString());
    str.append("\n");
    output << str;

    return output;
}

json json::operator,(json right) {
    json retVal;
    json united;

    if (this->harvestedFields.empty()) {
        united.harvestedFields.push_back(*this);
    } else {
        united.harvestedFields = this->harvestedFields;
    }
    united.harvestedFields.push_back(right);
    retVal = united;

    return retVal;
}

json json::operator[](json js) {
    assert(this->rv->type == array_t);

    if (js.harvestedFields.empty()) {
        ((Array *)this->rv)->contents.push_back(js);
    } else {
        ((Array *)this->rv)->contents = js.harvestedFields;
    }

    return *this;
}

json json::operator[](int index) {
    json j, len;
    int i = 0;

    if (!isArray(*this)) {
        cout << "Error: Indexing allowed only for ARRAY" << endl;
        exit(EXIT_FAILURE);
    }
    len = this->rv->size_of();

    if (index >= ((Number *) len.rv)->value) {
        cout << "Error: Out of bounds" << endl;
        exit(EXIT_FAILURE);
    }
    for (auto x : ((Array *)this->rv)->contents) {
        if (i == index) {
            j = x;
            break;
        }
        i++;
    }
    lvalue_p = this;
    return j;
}

json json::operator[](string key) {
    json exist, j;

    errorChecking(*this);

    if (!isObject(*this)) {
        cout << "Error: Indexing allowed only for OBJECT" << endl;
        exit(EXIT_FAILURE);
    }

    exist = this->rv->has_key(key);
    if (exist.rv->type == false_t) {
        string begin = "KEY '", end = "' not exist";
        j = json(new String(begin + key + end));
        j.isError = true;
    } else {
        for (auto x : ((Object *)this->rv)->contents) {
            if (x.key == key) {
                j = x.value;
                break;
            }
        }
    }
    lvalue_p = this;
    lvalue_key = key;

    return j;
}

/*      WORKABLE        */

Workable::Workable() {
    jsVal = nullptr;
}

Workable::Workable(json js) {
    jsVal = new json(nullptr);
    jsVal->rv = js.rv;
    jsVal->harvestedFields = js.harvestedFields;
}

Workable Workable::operator,(json right) {
    Workable retVal;

    if (this->jsVal == nullptr) { //periptwsi work , array (opou to , einai to APPEND)
        this->jsVal = new json(right.rv);
    } else { //periptwsi ... array , value 
        if (this->jsVal->rv->type != array_t) {
            cout << "Error: APPEND only work with ARRAY" << endl;
            exit(EXIT_FAILURE);
        } else {
            std::list<json> val = ((Array *) this->jsVal->rv)->contents;
            std::list<json> rightHarvested = right.harvestedFields;

            if (rightHarvested.empty()) {
                val.push_back(right);
            } else {
                val.insert(val.end(), rightHarvested.begin(), rightHarvested.end());
            }
            ((Array *) this->jsVal->rv)->contents = val;
        }
    }

    retVal = *this;

    return retVal;
}

Workable Workable::operator<<(json right) {
    if (this->jsVal == nullptr) { //periptwsi work , array (opou to , einai to APPEND)
        this->jsVal = new json(right.rv);
    } else {
        errorChecking(right);
        if (lvalue_p == nullptr) {//EMPTY object h array
            if (isArray(*jsVal)) {
                if (isArray(right)) {
                    ((Array *) this->jsVal->rv)->contents = ((Array *) right.rv)->contents;
                } else {
                    cout << "Error: Value must be ARRAY" << endl;
                    exit(EXIT_FAILURE);
                }
            } else if (isObject(*jsVal)) {
                if (isObject(right)) {
                    ((Object *) this->jsVal->rv)->contents = ((Object *) right.rv)->contents;
                } else {
                    cout << "Error: Value must be OBJECT" << endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                ((Number *)this->jsVal->rv)->value = 3;
            }
        } else {
            json state = json(new False());

            if (lvalue_p->rv->type == array_t) {
                errorChecking(*(this->jsVal));

                list<json> l1 = ((Array *) lvalue_p->rv)->contents;
                list<json>::iterator it1;
                for (it1 = l1.begin(); it1 != l1.end(); ++it1) {
                    if (isSameType(*it1, *(this->jsVal))) {
                        state = (*it1 == *(this->jsVal));
                        if (state.rv->type == true_t) {
                            l1.insert(it1, right);
                            l1.erase(it1);
                            break;
                        }
                    }
                }
                ((Array *) lvalue_p->rv)->contents = l1;
            } else if (lvalue_p->rv->type == object_t) {
                assert(!lvalue_key.empty());
                if (!((Object *) lvalue_p->rv)->insertObject(lvalue_key, right)) {
                    list<Object::objectElem> l2 = ((Object *) lvalue_p->rv)->contents;
                    list<Object::objectElem>::iterator it2;

                    if (l2.empty()) {
                        if (right.rv->type == object_t) {
                            l2 = ((Object *) right.rv)->contents;
                        } else {
                            cout << "Error: Value must be OBJECT" << endl;
                            exit(EXIT_FAILURE);
                        }
                    } else {
                        for (it2 = l2.begin(); it2 != l2.end(); ++it2) {
                            if (it2->key == lvalue_key) {
                                if (isSameType(it2->value, *(this->jsVal))) {
                                    state = (it2->value == *(this->jsVal));
                                    if (state.rv->type == true_t) {
                                        Object::objectElem elem;
                                        elem.key = lvalue_key;
                                        elem.value = right;

                                        l2.insert(it2, elem);
                                        l2.erase(it2);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    ((Object *) lvalue_p->rv)->contents = l2;
                }
            }
        }
        //Reset global variables
        lvalue_p = nullptr;
        lvalue_key.clear();
    }

    return *this;
}

/* NUMBER */
Number::Number(double d) {
    type = number_t;
    value = d;
}

string Number::toString() {
    return to_string(value);
}

bool Number::isEqualWith(json val) {
    return this->value == ((Number *) val.rv)->value;
}

json Number::type_of() {
    return json(new String("number"));
}

/* STRING */

String::String(string s) {
    type = string_t;
    value = s;
}

string String::toString() {
    string retVal = "\"";
    retVal.append(value);
    retVal.append("\"");

    return retVal;
}

bool String::isEqualWith(json val) {
    return this->value == ((String *) val.rv)->value;
}

json String::type_of() {
    return json(new String("string"));
}

/*  TRUE    */
True::True() : value(true) {
    type = true_t;
}

string True::toString() {
    return "true";
}

bool True::isEqualWith(json val) {
    return val.rv->type == true_t;
}

json True::type_of() {
    return json(new String("boolean"));
}

/*  FALSE   */
False::False() : value(false) {
    type = false_t;
}

string False::toString() {
    return "false";
}

bool False::isEqualWith(json val) {
    return val.rv->type == false_t;
}

json False::type_of() {
    return json(new String("boolean"));
}

/*  NULL    */
Null::Null() {
    type = null_t;
}

string Null::toString() {
    return "null";
}

bool Null::isEqualWith(json val) {
    return true;
}

json Null::type_of() {
    return json(new String("null"));
}

/*  OBJECT  */
Object::Object() {
    type = object_t;
}

Object::Object(list<Object::objectElem> l) {
    type = object_t;
    contents = l;
}

bool Object::insertObject(string key, json val) {
    bool inserted = false;
    if (!containsKey(key)) {
        objectElem elem;
        elem.key = key;
        elem.value = val;
        contents.push_back(elem);
        inserted = true;
    }

    return inserted;
}

bool Object::containsKey(string key) {
    bool retVal = false;
    if (!contents.empty()) {
        for (auto val : contents) {
            if (val.key == key) {
                retVal = true;
                break;
            }
        }
    }
    return retVal;
}

string Object::toString() {
    string str;
    if (contents.empty()) {
        str = "{}";
    } else {
        str = "{";
        for (auto x : contents) {
            str.append("\"");
            str.append(x.key);
            str.append("\" : ");
            str.append(x.value.rv->toString());
            str.append(", ");
        }
        str = str.erase(str.size() - 2, 2);
        str.append("}");
    }
    return str;
}

bool Object::isEqualWith(json val) {
    bool retVal = false;
    bool keyState;
    json valueState;
    list<objectElem> l1, l2;
    l1 = contents;
    l2 = ((Object *) val.rv)->contents;
    if (l1.size() == l2.size()) {
        list<objectElem>::iterator it1, it2;
        it1 = l1.begin();
        it2 = l2.begin();
        retVal = true;
        for (; it1 != l1.end() && it2 != l2.end(); ++it1, ++it2) {
            keyState = ((*it1).key == (*it2).key);
            valueState = ((*it1).value == (*it2).value);
            if ((keyState == false) || (valueState.rv->type == false_t)) {
                retVal = false;
                break;
            }
        }
    }
    return retVal;
}

json Object::size_of() {
    return json(new Number(this->contents.size()));
}

json Object::is_empty() {
    json j;
    if (this->contents.empty()) {
        j = json(new True());
    } else {
        j = json(new False());
    }
    return j;
}

json Object::has_key(std::string key) {
    json j = json(new False());
    for (auto x : contents) {
        if (x.key == key) {
            j = json(new True());
            break;
        }
    }
    return j;
}

json Object::type_of() {
    return json(new String("object"));
}

/*  ARRAY   */

Array::Array() {
    type = array_t;
}

Array::Array(std::list<json> l) {
    type = array_t;
    contents = l;
}

string Array::toString() {
    string retVal;
    if (contents.empty()) {
        retVal = "[]";
    } else {
        retVal = "[";
        for (json a : contents) {
            retVal.append(a.rv->toString());
            retVal.append(", ");
        }
        retVal = retVal.erase(retVal.size() - 2, 2);
        retVal.append("]");
    }
    return retVal;
}

bool Array::isEqualWith(json val) {
    bool retVal = false;
    json state;
    list<json> l1, l2;
    l1 = contents;
    l2 = ((Array *) val.rv)->contents;
    if (l1.size() == l2.size()) {
        list<json>::iterator it1, it2;
        it1 = l1.begin();
        it2 = l2.begin();
        retVal = true;
        for (; it1 != l1.end() && it2 != l2.end(); ++it1, ++it2) {
            state = ((*it1) == (*it2));
            if (state.rv->type == false_t) {
                retVal = false;
                break;
            }
        }
    }
    return retVal;
}

json Array::size_of() {
    return json(new Number(this->contents.size()));
}

json Array::is_empty() {
    json j;
    if (this->contents.empty()) {
        j = json(new True());
    } else {

        j = json(new False());
    }
    return j;
}

json Array::type_of() {
    return json(new String("array"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*     JSON OPERATORS     */
json SIZE_OF(json x) {
    return x.rv->size_of();
}

json IS_EMPTY(json x) {
    return x.rv->is_empty();
}

json HAS_KEY(json x, std::string key) {
    return x.rv->has_key(key);
}

json TYPE_OF(json x) {
    return x.rv->type_of();
}

void errorChecking(json err) {
    if (err.isError == true) {
        cout << "Error: " << err.rv->toString() << endl;
        exit(EXIT_FAILURE);
    }
}