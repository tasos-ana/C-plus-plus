#include <cmath>
#include <assert.h>
#include <valarray>
#include <stdlib.h>
#include "JSONlang_overloads.h"
#include "JSONlang_classes.h"

json * lvalue_p = nullptr;
std::string lvalue_key;

using namespace std;

void operator-(json right) {
    if (isArray(right)) {
        ((Array *) right.rv)->contents.clear();
    } else if (isObject(right)) {
        ((Object *) right.rv)->contents.clear();
    } else {
        if (lvalue_p != nullptr) {
            json state = json(new False());
            if (lvalue_p->rv->type == array_t) {
                errorChecking(right);

                list<json> l1 = ((Array *) lvalue_p->rv)->contents;
                list<json>::iterator it1;
                for (it1 = l1.begin(); it1 != l1.end(); ++it1) {
                    if (isSameType(*it1, right)) {
                        state = (*it1 == right);
                        if (state.rv->type == true_t) {
                            l1.erase(it1);
                            break;
                        }
                    }
                }
                ((Array *) lvalue_p->rv)->contents = l1;
            } else if (lvalue_p->rv->type == object_t) {
                assert(!lvalue_key.empty());
                if (((Object *) lvalue_p->rv)->containsKey(lvalue_key)) {
                    list<Object::objectElem> l2 = ((Object *) lvalue_p->rv)->contents;
                    list<Object::objectElem>::iterator it2;

                    if (l2.empty()) {
                        if (right.rv->type == object_t) {
                            l2 = ((Object *) right.rv)->contents;
                        } else {
                            cout << "rvalue isn't object" << endl;
                            exit(EXIT_FAILURE);
                        }
                    } else {
                        for (it2 = l2.begin(); it2 != l2.end(); ++it2) {
                            if (it2->key == lvalue_key) {
                                if (isSameType(it2->value, right)) {
                                    state = (it2->value == right);
                                    if (state.rv->type == true_t) {
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
        } else {
            cout << "Error: ERASE only ARRAY or OBJECT" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

/*      ARITHMETIC OPERATORS     */
json operator+(json left, json right) {
    json retVal;
    if (isNumber(left) && isNumber(right)) {
        double val;
        val = ((Number *) left.rv)->value + ((Number *) right.rv)->value;
        retVal = json(new Number(val));
    } else if (isString(left) && isString(right)) {
        string val;
        val.append(((String *) left.rv)->value);
        val.append(((String *) right.rv)->value);
        retVal = json(new String(val));
    } else if (isArray(left) && isArray(right)) {
        std::list<json> val, rightList;
        rightList = ((Array *) right.rv)->contents;

        val = ((Array *) left.rv)->contents;
        val.insert(val.end(), rightList.begin(), rightList.end());
        retVal = json(new Array(val));
    } else if (isObject(left) && isObject(right)) {
        std::list<Object::objectElem> val, rightVal;

        rightVal = ((Object *) right.rv)->contents;
        for (auto x : rightVal) {
            if (!((Object *) left.rv)->insertObject(x.key, x.value)) {
                cout << "Error: Can't merge objects. Key already exist" << endl;
                exit(EXIT_FAILURE);
            }
        }

        val = ((Object *) left.rv)->contents;
        retVal = json(new Object(val));
    } else {
        cout << "Error: invalid type for '+' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return retVal;
}

json operator-(json left, json right) {
    double val;
    if (isNumber(left) && isNumber(right)) {
        val = ((Number *) left.rv)->value - ((Number *) right.rv)->value;
    } else {
        cout << "Error: invalid type for '-' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return json(new Number(val));
}

json operator*(json left, json right) {
    double val;
    if (isNumber(left) && isNumber(right)) {
        val = ((Number *) left.rv)->value * ((Number *) right.rv)->value;
    } else {
        cout << "Error: invalid type for '*' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return json(new Number(val));
}

json operator/(json left, json right) {
    double val;
    if (isNumber(left) && isNumber(right)) {
        val = ((Number *) left.rv)->value / ((Number *) right.rv)->value;
    } else {
        cout << "Error: invalid type for '/' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return json(new Number(val));
}

json operator%(json left, json right) {
    double val;
    if (isNumber(left) && isNumber(right)) {
        val = fmod(((Number *) left.rv)->value, ((Number *) right.rv)->value);
        ;
    } else {
        cout << "Error: invalid type for '%' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return json(new Number(val));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*      LOGIC OPERATORS     */
json operator&&(json left, json right) {
    json j;
    if (isBool(left) && isBool(right)) {
        if (left.rv->type == true_t && right.rv->type == true_t) {
            j = json(new True());
        } else {
            j = json(new False());
        }
    } else {
        cout << "Error: invalid type for '&&' operator" << endl;
        exit(EXIT_FAILURE);
    }
    return j;
}

json operator||(json left, json right) {
    json j;
    if (isBool(left) && isBool(right)) {
        if (left.rv->type == false_t && right.rv->type == false_t) {
            j = json(new False());
        } else {
            j = json(new True());
        }
    } else {
        cout << "Error: invalid type for '||' operator" << endl;
        exit(EXIT_FAILURE);
    }
    return j;
}

json operator!(json js) {
    json j;
    if (isBool(js)) {
        if (js.rv->type == true_t) {
            j = json(new False());
        } else {
            j = json(new True());
        }
    } else {
        cout << "Error: invalid type for '!' operator" << endl;
        exit(EXIT_FAILURE);
    }

    return j;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*      EQUALITY OPERATORS  */
json operator==(json left, json right) {
    bool retVal = false;
    if (isSameType(left, right)) {
        retVal = left.rv->isEqualWith(right);
    } else {
        cout << "Error: invalid type for equality operator" << endl;
        exit(EXIT_FAILURE);
    }
    json j;
    if (retVal) {
        j = json(new True());
    } else {
        j = json(new False());
    }
    return j;
}

json operator!=(json left, json right) {
    json j;
    j = (left == right);
    if (j.rv->type == true_t) {
        j = json(new False());
    } else {
        j = json(new True());
    }

    return j;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool isNumber(json value) {
    return value.rv->type == number_t;
}

bool isString(json value) {
    return value.rv->type == string_t;
}

bool isArray(json value) {
    return value.rv->type == array_t;
}

bool isObject(json value) {
    return value.rv->type == object_t;
}

bool isBool(json value) {
    return (value.rv->type == true_t || value.rv->type == false_t);
}

bool isSameType(json value1, json value2) {
    return ( (value1.rv->type == value2.rv->type) || (isBool(value1) && isBool(value2)));
}