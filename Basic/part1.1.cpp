// Askisi 1 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166


#include "std_lib_facilities.h"


int main()
{
	cout<<"\n"; //Afinoume mia keni grammi etsi gia emfanisiakous logous
	cout<<"Integer "<<"Square  "<<"Cube    \n";// emfanizoume tin prwti grammi pou zitithike
	for (int i=0; i<11; i++)//Afou theloume na emfanisoume square kai cube gia 10 arithmous dimiourgoume mia for loop pou ekteleite 10 fores
	{
		//ta kena metaksi tis arxis twn arithmwn tha prepei na einai 7
		if (i<4)       cout<<i<<"       "<<i*i<<"       "<<i*i*i<<"\n";// An eimaste stous prwtous 4 arithmous opou integer kai square einai monopsifioi
									       //tote emfanizoume ena sigkekrimeno plithos whitespace wste na uparxei h swsti stoixisi
		else if (i>9)  cout<<i<<"      "<<i*i<<"     "<<i*i*i<<"\n";   //An eimaste gia integer=10 tote exoume allo plithos kenon afou  integer 2 psifia
									       //square 3 psifia kai cube 4 psifia.
		else           cout<<i<<"       "<<i*i<<"      "<<i*i*i<<"\n"; //se kathe alli periptosi dld gia  4<int<9 exoume diaforetiko plithos kenon metaksi
									       //square kai cube!!!
	}
	cout<<"\n";
	return 0;
}

// Askisi 1 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166
