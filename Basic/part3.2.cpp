//Hy-150-Programming
//Assigment 3
//Part 2
//Writed By Taso Anastasa
//A.M 3166
#include "std_lib_facilities.h"

void data_output(int , string, double);
void tittle_output(string,string,string);
int print();
int read();
string file="members.txt";

int main()
{
	read();//With that fucntion we read account,name and balance that give user and store it on file with name members.txt
	print();//With that fuction we print on screen the data of the file members.txt
	keep_window_open();
	keep_window_open();
	return 0;	
}

void data_output(int account, string name, double balance)
{
	cout<<left<<setw(10)<<account<<setw(13)<<name<<setw(7)<<setprecision(2)<<right<<balance<<endl;//Tha fuction print the account,name and balance, with some whitespace as a result data looks better!
}

void tittle_output(string name1, string name2, string name3)
{
	cout<<left<<setw(10)<<name1<<setw(13)<<name2<<setw(7)<<setprecision(2)<<right<<name3<<endl;//Tha fuction print the Tittle "Account" "Name" "Balance" with some whitespace as a result data looks better!
}

int read()
{
    ofstream ost(file.c_str());    // ost is an output stream for a file named file
    if (!ost) error("can't open output file ",file);//check for error when the file cant opened
	ost<<"Account"<<' '<<"Name"<<' '<<"Balance"<<endl;//Put that data in file!
	int account;
	string name;
	double balance;
	for(;;)
	{
		cout<<"Account:";
		if (cin>>account) cout<<"Name:";//Read the data and if was int then continue
		else break;
		if (cin>>name) cout<<"Balance:";//Read the data and if was string then continue
		else break;
		if (cin>>balance) {} //Read the data and if was double then continue
		else break;
		ost<<account<<"    "<<name<<"    "<<balance<<endl;//Put the data that read before in the file
		cout<<endl;
	}
	return 0;
}

int print()
{
	int account;
	string name,name1,name2,name3;//The variables name1,name2,name3 used for store tittles.
	double balance;
	ifstream ist(file.c_str());    // ist is an input stream for a file named file
    if (!ist) error("can't open output file ",file);//If we cant open file we print that message
	cout<<endl<<endl;
	for (;;) 
		{
			if (ist>>name1>>name2>>name3) tittle_output(name1,name2,name3);//If we are on line we tittle we print data with format string string string
			else if (ist>>account>>name>>balance) data_output(account,name,balance);//Else we print with format int string double
			else	return 0;
		}
}

//Hy-150-Programming
//Assigment 3
//Part 1
//Writed By Taso Anastasa
//A.M 3166