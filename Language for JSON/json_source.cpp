#include "JSONlang.h"


PROGRAM_BEGIN
///*WORKING*/

//define emptyObj json with empty object
JSON(emptyObj) = OBJECT{}

//define emptyArray json with empty array
JSON(emptyArray) = ARRAY

//define book json with an object containing data for a book
JSON(book) = OBJECT{
    KEY(title) : STRING("Gone Girl"),
    KEY(published) : NUMBER(2012),
    KEY(type) : STRING("Thriller"),
    KEY(author) : OBJECT
    {
        KEY(firstname) : STRING("GILLIAN"),
        KEY(sirname) : STRING("FLYNN"),
        KEY(age) : NUMBER(45)
    }
}

//define week_temperatures json with an array of numbers
JSON(week_temperatures) = ARRAY [
NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20),
NUMBER(19), NUMBER(18.5), NUMBER(19)
]

//PRINT emptyArray, emptyObj, book, week_temperatures

//define students json with an array of objects representing students
JSON(students) = ARRAY [
OBJECT{
    KEY(name) : STRING("Nikos Nikolaou"),
    KEY(id) : NUMBER(4444),
    KEY(grades) : ARRAY[
    OBJECT
    { KEY(hy100) : NUMBER(7.5)},
    OBJECT{ KEY(hy150) : NUMBER(8)}
    ]
}
]

//change 3rd day temperature from 19 to 22
SET week_temperatures[2] ASSIGN NUMBER(22)
//add email address for 1st student
SET students[0]["email"] ASSIGN STRING("csd444@csd.uoc.gr")
//assign new object in emptyObj json
SET emptyObj ASSIGN OBJECT{
    KEY(a) : STRING("alpha")
}

//appends values 23, 22, 20 to the end of the temperature array
SET week_temperatures APPEND NUMBER(23), NUMBER(22), NUMBER(20)
//appends a grade for course hy255
SET students[0]["grades"] APPEND OBJECT{KEY(hy255) : NUMBER(9)}


//ERASE book["author"]["age"] //removes age from author object of book
//ERASE book["type"] //removes type of book
//ERASE book //removes all book data, now book is an empty object

JSON(hy352_nik) = OBJECT{KEY(exam) : NUMBER(7), KEY(project) : NUMBER(8)}
JSON(students2) = ARRAY [
OBJECT{
    KEY(name) : STRING("Nikos ") + STRING("Nikolaou"),
    KEY(id) : NUMBER(4444),
    KEY(grades) : ARRAY[
    OBJECT
    {
        KEY(hy352) :
        hy352_nik["exam"] * NUMBER(0.75) + hy352_nik["project"] * NUMBER(0.25)
    }
    ]
}
]

PRINT book["title"] //prints:Gone Girl
PRINT book["author"] //prints:{firstname:”Gillian”,sirname:“Flynn”,age: 45}
PRINT book //prints: the whole json for book
PRINT HAS_KEY(book, "author") //prints: true
//prints: Book has key author? True
PRINT STRING("Book has key author? "), HAS_KEY(book, "author")
        
PROGRAM_END
