//Hy-150-Programming
//Assigment 2
//Part 1
//Writing by Taso Anastasa
//A.M 3166

#include "std_lib_facilities.h"

int s; //The s was one global variable that take the result that returning every time the function power.
int  power(int base, int exponent);

int main()

{
int x,y,sum;//As base = x , exponent=y, the sum was the variable how the function returning the result of base^exponent.
cout<< "Please gave first the base and then the exponent.\n";
cin>>x>>y;//Scanning x=base and y=exponent as tolding and before.
while (y<0)//We check if exponent was negative or positive.
{
	cout<<"Please give a positive exponent\n";//if the number was negative then we must give new one!
	cin>>y;
}
s=x;//Make the variable s = with base because of case exponent = 1 then the result was base, as a result the s must have one value.
sum=power(x,y);
cout<<x<<'^'<<y<<'='<<sum<<'\n';//Printing the result with type base^exponent= ... (for example 2^2=4)
return 0;
}


int power(int base,int exponent)
{
if (exponent==1) return s;//First case was the exponent to be = with 1, that mean base^1 = base.
else if (exponent==0) return 1;//All we known that one number towering in zero give as a result always 1.
else//For another value of exponent we got....
{
s=s*base;//We multiply the s by previous s with base, because  2^3 mean 2*2*2;
power(base,exponent-1);//Entering again on function but with exponent reduced by one from the last value.
}
/* That's do it because if we need to found the base in the exponent power we must multiply base with base exponent times!!
   With function power  achieve that!!
*/

return s;
}
//Hy-150-Programming
//Assigment 2
//Part 1
//Writing by Taso Anastasa
//A.M 3166

