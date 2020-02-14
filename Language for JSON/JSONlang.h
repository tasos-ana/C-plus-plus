#ifndef JSONLANG_H
#define JSONLANG_H

#include <iostream>
#include "JSONlang_classes.h"
#include "JSONlang_overloads.h"

#define PROGRAM_BEGIN   ; int main(int argc, char** argv){
#define PROGRAM_END     ; return 0; }

#define JSON(x)         ; json x

#define NUMBER(x)       json(new Number(x))
#define STRING(x)       json(new String(x))
#define TRUE            json(new True())
#define FALSE           json(new False())

// undefine NULL from iostream library
#undef  NULL
#define NULL            json(new Null())

#define OBJECT          json 
#define ARRAY           json(new Array())

#define KEY(x)          key : STRING(#x), value

json SIZE_OF(json x);
json IS_EMPTY(json x);
json HAS_KEY(json x, std::string key);
json TYPE_OF(json x);

#define SET             ; Workable() << 
#define ASSIGN          <<
#define APPEND          ,
#define ERASE           ; -

/*
 * Anti gia << exoume valei ,(comma) epeidi exei tin mikroterh proteraiothta
 */
#define PRINT           ; std::cout , 
#endif /* JSONLANG_H */

