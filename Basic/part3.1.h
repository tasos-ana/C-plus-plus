//Hy-150-Programming
//Assigment 3
//Part 1
//Writed By Taso Anastasa
//A.M 3166

#include "std_lib_facilities.h"

class complex
{
    complex friend operator+(complex&,complex&);//Here was the declaration of operator +
	complex friend operator*(complex&,complex&);//Here was the declaration of operator *
	friend istream &operator >>(istream &,complex&);//Here was the declaration of operator >>
	friend ostream &operator<<(ostream&, complex&);//Here was the declaration of operator <<
	int friend operator==(complex&,complex&);//Here was the declaration of operator ==
	int friend operator!=(complex&,complex&);//Here was the declaration of operator !=
private:
		int real,imagine;//The two variables that store real and image number for each complex
public:	
	complex(int,int);//the declaration of contractor
	void read_first(complex&);//Declaration of the function read_first, that reading first complex
	void read_second(complex&);//Declaration of the function read_second, that reading second complex
	void read_operator (complex&, complex&);//Declaration of the function read_operator, that reading the operator and check if it's correct!
	void start(complex&, complex&, complex&);//That fuction call from main programm to start all the functions!
};
//Hy-150-Programming
//Assigment 3
//Part 1
//Writed By Taso Anastasa
//A.M 3166