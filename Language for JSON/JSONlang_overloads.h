#ifndef JSONLANG_OVERLOADS_H
#define JSONLANG_OVERLOADS_H

#include "JSONlang_classes.h"

extern json * lvalue_p;
extern std::string lvalue_key;

void operator-(json right);

/*      ARITHMETIC OPERATORS     */
json operator+(json left, json right);
json operator-(json left, json right);
json operator*(json left, json right);
json operator/(json left, json right);
json operator%(json left, json right);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*      LOGIC OPERATORS     */
json operator&&(json left, json right);
json operator||(json left, json right);
json operator!(json js);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*      EQUALITY OPERATORS  */
json operator==(json left, json right);
json operator!=(json left, json right);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*      UTIL FUNCTIONS      */
bool isNumber(json value);
bool isString(json value);
bool isArray(json value);
bool isObject(json value);
bool isBool(json value);
bool isSameType(json value1, json value2);

#endif /* JSONLANG_OVERLOADS_H */

