//Hy-150-Programming
//Assigment 2
//Part 2
//Writing by Taso Anastasa
//A.M 3166


#include "std_lib_facilities.h"


int main()
{
int i,j,x;
cout<<"Please give one number for the side of the square!\n";
	cin>>x;//Here we read how much stars want the user to give as side of the square.
	while (x<0)//Because we need one positive number we check for validity.
	{
	cout<<"You must give one positive number. Please try again!\n";
	cin>>x;//If the number=x it was negative then printing the previous message and scanning for new number.
	}
	for (i=1; i<=x;i++)//Now we must do on for loop  with x loops, and inside of that for loop
	{
		for(j=1; j<=x; ++j)//we run another one for loop with x loops.
				   //With that for loop we print x starts in one row.
		        	   //With previous we print x starts in on column.
		{
			cout<<"*";//Printing the start
		}
		cout<<"\n";//After print x starts in same row we must change line.
	}
return 0;
}
//Hy-150-Programming
//Assigment 2
//Part 2
//Writing by Taso Anastasa
//A.M 3166
