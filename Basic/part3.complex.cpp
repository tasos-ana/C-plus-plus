//Hy-150-Programming
//Assigment 3
//Part 1
//Writed By Taso Anastasa
//A.M 3166

#include "part1.h"
//Defination of class fuctions,constractor
complex::complex(int x,int y): real(x) , imagine(y) {}//The constructor that make the object.real = x and object.imagine = y
	void complex::read_first(complex& a)
	{
		cout<<endl<<"Give the first complex (type: real + imagine*i).\n";//Give one output to the console that told on user what he must to give!
		cin>>a;//Reading the real and imagine numbers! >> was the operator that we will see later!
	}

	void complex::read_second(complex& b)
	{
		cout<<endl<<"Give the second complex (type: real + imagine*i).\n";//Give one output to the console that told on user what he must to give!
		cin>>b;//Reading the real and imagine numbers! >> was the operator that we will see later!
	}

	void complex::read_operator (complex& k, complex& l)
	{
		char op;
		cout<<endl<<"Give the operator that you want to use (+) or (*) or (=) or (!).\n";//We told on user that now must give 1 of the following operators
		cin>>op;
		switch (op)//We check what operator he give!
		{
		case '+':
			k+l;
			break;
		case '*':
			k*l;
			break;
		case '=':
			k==l;
			break;
		case '!':
			k!=l;
			break;
		default://If not 1 of the previous operators then print on console the following message.
			cout<<"You give wrong operator please try again.\n";
		}
	}

	void complex::start(complex& a, complex& b, complex& c)//The following fuction start the programm!
	{
	a.read_first(a);//Scanning the first complex on object a
	b.read_second(b);//Scanning the second complex on object b
	c.read_operator(a,b);//Scanning the operator!
	}

complex operator+ (complex& a, complex& b)
{
	complex c(a.real+b.real,a.imagine+b.imagine);//If user choos the operator + we do the following procress
	cout<<a<<" + "<<b<<" = "<<c<<endl;//After we put on screen the result!
	return c;
}

complex operator* (complex& a, complex& b)
{
	complex c((a.real*b.real)-(a.imagine*b.imagine),(a.real*b.imagine)+(a.imagine*b.real));//If user choos the operator + we do the following procress
	cout<<a<<" * "<<b<<" = "<<c<<endl;//After we put on screen the result!
	return c;
}

ostream &operator<<(ostream &output, complex &a)
{
	output <<"("<<a.real<<" + "<<a.imagine<<"i)";//Here we print the real and imagine like that (x + yi) ( x=real, y=imagine)
	return output;
}

istream &operator>>(istream &input,complex &b)
{
	input>>b.real;
	cout<<"+"<<endl;
	input>>b.imagine;
	cout<<"*i"<<endl;
	return input;
}

int operator ==(complex& a, complex& b)
{
	if ((a.real==b.real) && (a.imagine==b.imagine))//If the complex was equal 
	{
		cout<<"The two complex that you gave it's equal.\n";//We print tha message
		cout<<a<<" == "<<b<<endl;//And print the complexs like (a+bi)=(c+di)
		return 1;
	}
	else //If not the comples equal.
	{
		cout<<"The two complex that you gave it's unequal.\n";//We print tha message
		cout<<a<<" != "<<b<<endl;//And print the complexs like (a+bi)!=(c+di)
		return 0;
	}
}

int operator !=(complex& a, complex& b)
{
	if ((a.real!=b.real) || (a.imagine!=b.imagine))//If not the complexs equal.
	{
		cout<<"The two complex that you gave it's unequal.\n";//We print tha message
		cout<<a<<" != "<<b<<endl;//And print the complexs like (a+bi)!=(c+di)
		return 0;
	}
	else//If  the complexs equal.
	{
		cout<<"The two complex that you gave it's equal.\n";//We print tha message
		cout<<a<<" == "<<b<<endl;//And print the complexs like (a+bi)=(c+di)
		return 1;
	}
}

//Hy-150-Programming
//Assigment 3
//Part 1
//Writed By Taso Anastasa
//A.M 3166
