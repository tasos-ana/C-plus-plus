//Hy-150-Programming
//Assigment 2
//Part 3
//Writed By Taso Anastasa
//A.M 3166

/*
The following class run with the commands:

	Rational s,a,b,c;
	s.start(a,b,c);
	//a was the object that got the first rational, b the object that got the second and c the object that got the results!
*/
#include "std_lib_facilities.h"

class Rational
{
	Rational friend operator+(Rational&,Rational&);
	Rational friend operator-(Rational&,Rational&);
	Rational friend operator*(Rational&,Rational&);
	Rational friend operator/(Rational&,Rational&);
	private:
		int num, den;//num = numerator and den= denominator
	public:
		class DivisionWithZero { };// That class was for exception if we take as denominator zero.
		class DivisionNumerator { };//Tha class was for exception if we try do division / with 0 as numerator for example ((2/3)/(0/2))
		/*In constructor Rational we initialze the numerator=0 and denominator=1 because that numbers it is the minimum int and no negative that can take
		  numerator and denominator. Also we check if denominator it was 0 and throw the expeption if it is true!*/
		Rational(int numerator=0,int denominator=1) : num(numerator), den(denominator) { if (den==0) throw DivisionWithZero(); }
		/*	Function read_first:
				Scanning the numerator and denominator for first national after puting on screen the correct message.
			Fuction read_second:
				Same with fuction read_first but this time for second national.
			Fuction read_operator:
				Scanning what operation want user to use and checking if the given data was correct( denominator<>0).
			Fuction print_data:
				Printing on screen the first and second rational that we read and the operator that use for example (2/3+5/6).
			Fuction print_result:
				Printing on screen the result that found as rational first and then as double.
			Fuction Convert:
				Make the result from int to double.
			Fuction start:
				Start the correct functions and the magic begin.
		*/	
		void read_first()
		{
			int x,y;
			cout<<endl<<"Give the first rational number (type: numerator/denominator)\n";
			cin>>x;//Scanning the numerator of first rational.
			cout<<"/"<<endl;//I'm print that for sawing better on screen what was the first rational.
			cin>>y;//Scanning the denominator of first rational.
			num=x;
			den=y;
		}
		void read_second()
		{
			int x,y;
			cout<<endl<<"Give the second rational number (type: numerator/denominator)\n";
			cin>>x;//Scanning the numerator of second rational.
			cout<<"/"<<endl;//I'm print that for sawing better on screen what was the second rational.
			cin>>y;//Scanning the denominator of second rational.
			num=x;
			den=y;
		}
		void read_operator( Rational& k, Rational& l)
		{
			try
			{
				char op;
				cout<<endl<<"Give the operator that you want to use (+) or (-) or (*) or (/): ";
				cin>>op;//Scanning the operator.
				switch (op)//We check the variable op
				{
        			case '+': // if was the (+)
						k+l;
						break;
					case '-': // if was the (-)
						k-l;
						break;
					case '*': // if was the (*)
						k*l;
						break;
					case '/': // if was the (/)
						if (l.num==0) throw DivisionNumerator();
						k/l;
						break;
					default: //Else we print the next message end stop the programm.
						cout<<"The operator that you choose isn't one of the (+) , (-) , (*) , (/). Please try again!\n";
				}
			}
			catch (DivisionWithZero&)// if the constructor throw an exception then we catch it and print the next message.
			{
				cerr<<"ERROR!!You gave as denominator the number zero!\n";
			}
			catch (DivisionNumerator&)
			{
				cerr<<"ERROR!! You cant use the operator (/) if the numerator of the second rational was zero!\n";
			}
			
		}
		void print_data()
		{
			cout<<" "<<num<<"/"<<den<<" ";
		}
		void print_result() 
		{ 
			cout<<"= "<<num<<"/"<<den<<" = "<<Convert()<<endl;
		}
		double Convert()
		{
			double n,d;
			n=static_cast<double>(num);//We converting num from int to double.
			d=static_cast<double>(den);//we converting den from int to double.
			return n/d;//We returing the division of num with den that was a double number.
		}
		void start(Rational& a,Rational& b, Rational& c)
		{
			a.read_first();
			b.read_second();
			c.read_operator(a,b);
		}
};
//In next operator function (+) we got the rational a(?,?) and rational b(?,?)
Rational operator+ ( Rational& a,  Rational& b)
{
	Rational c(a.num*b.den+b.num*a.den,a.den*b.den); //Here we make creat the object c that contains the result of a+b,
	a.print_data();//Printing the first data that use with operator +.
	cout<<"+";//Adding on screen the corect operator.
	b.print_data();//Printing the second data that use with operator +.
	c.print_result();//Printing the results.
	return c;//We return to the class the c.num and c.den .
}

//In next operator function (-) we got the rational a(?,?) and rational b(?,?)
Rational operator-(Rational& a,  Rational& b)
{
    Rational c(a.num*b.den-b.num*a.den,a.den*b.den);//Here we make creat the object c that contains the result of a+b,
	a.print_data();//Printing the first data that use with operator +.
	cout<<"-";//Adding on screen the corect operator.
	b.print_data();//Printing the second data that use with operator +.
	c.print_result();//Printing the results.
	return c;//We return to the class the c.num and c.den .
}

//In next operator function (*) we got the rational a(?,?) and rational b(?,?)
Rational operator* (Rational& a,  Rational& b)
{
	Rational c(a.num*b.num,a.den*b.den);//Here we make creat the object c that contains the result of a+b.
	a.print_data();//Printing the first data that use with operator +.
	cout<<"*";//Adding on screen the corect operator.
	b.print_data();//Printing the second data that use with operator +.
	c.print_result();//Printing the results.
	return c;//We return to the class the c.num and c.den .
}

//In next operator function (/) we got the rational a(?,?) and rational b(?,?)
Rational operator/ (Rational& a,  Rational& b)
{
	Rational c(a.num*b.den,a.den*b.num);//Here we make creat the object c that contains the result of a+b,
	a.print_data();//Printing the first data that use with operator +.
	cout<<"/";//Adding on screen the corect operator.
	b.print_data();//Printing the second data that use with operator +.
	c.print_result();//Printing the results.
	return c;//We return to the class the c.num and c.den .
}
//Hy-150-Programming
//Assigment 2
//Part 3
//Writed By Taso Anastasa
//A.M 3166
