// Askisi 1 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166

#include "std_lib_facilities.h"

int main()
{
//N einai to plithos ton akeraion pou thelei o xristis na diavastoun
//min einai o mikroteros arithmos apo aftous pou diavastikan
//num einai o arithmos pou diavazete kathe fora
int N,min,num;
cout<<"Parakalw dwste to plithos ton arithmon N pou thelete na sigkrinete: ";
cin>>N;// diavazoume ton N arithmo
cout<<"\n"<<"Dwste enan enan tous arithmous gia na vrethei o mikroteros!\n";
cin>>min;//ekxwrtoume ton prwto arithmo pou tha diavasoume ston min
for (int i=0; i<N-1; i++)// ekteloume mia epanalipsi N-1 fores
{
	cin>>num;//Diavazoume enan akeraio
	if (num<min) min=num;//Sigrinoume kai ean einai o arithmos pou diavasame mikroteros apo ton min tote ton ekxoroume ston min
}
cout<<"O mikroteros arithmos einai: "<<min<<"\n";// emfanizoume katalilo minima kai ton min
return 0;
}

// Askisi 1 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166
