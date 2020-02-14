// Askisi 2 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166

#include "std_lib_facilities.h"
int main()
{
//xiliometra einai ta km pou dienise o odiges kai ta opoia diavazoume
//litra einai ta l pou ekapse o odiges kai ta opoia diavazoume
//opou i einai o arithmos tou taksidiou (p.x prwto,deftero,trito)
//sum_litra einai ta sunolika litra pou dienise o odigos
//sum_xiliometra einai ta sunolika xiliometra pou dienise o  odigos
//xil_ana_litra einai to apotelesma tis dieresis tou xiliometra/litra
//katanalwsi einai to apotelesna tis praksis (100*sum_litra)/sum_xiliometra
// einai double oi metavlites giati ean dwthei 1 km kai 2 lt tote to apotelesma ean itan int tha ebgane 0 enw twra 0,5
double xiliometra,i=1,litra,sum_litra=0,sum_xiliometra=0;
double xil_ana_lit,sum=0,katanalwsi;
cout<<"Parakalw dwste prwta ta km kai stin sunexeia ta litra.\n";
cin>>xiliometra>>litra;// diavazoume ta km kai lt
while (xiliometra!=-1 && litra!=-1)// ean kapoio apo ta duo pou diavasame dn einai -1 tote sunexizoume
{
	xil_ana_lit=xiliometra/litra;//upologizoume ta km/l
	sum=sum+xil_ana_lit;//kratame stin metavliti sum ta sunolika km/l
	sum_xiliometra=sum_xiliometra+xiliometra;//kratame stin sum_xiliometra ta sunolika xiliometra
	sum_litra=sum_litra+litra;//kratame ta sunolika litra
	katanalwsi=((100*sum_litra)/sum_xiliometra);//upologizoume tin katanalwsi
	cout<<"Taksidi "<<i<<"\n";// emfanizoume se poio taksidi eimaste
	cout<<"Trexon taksidiou-> "<<xil_ana_lit<<"km/l \n";// emfanizoume ta km/l tou trexon taksidiou
	cout<<"Sunolika taksidia-> "<<sum<<"km/l \n";// emfanizoume ta km/l ews to trexon taksidi
	cout<<"Sunoliki katanalwsh-> "<<katanalwsi<<"l/100km \n";// emfanizoume tin sunoliki katanalwsi
	cin>>xiliometra>>litra;// diavazoume ta xiliometra kai ta litra ksana
	i++;//pigainoume sto epomeno taksidi
}
return 0;
}

// Askisi 2 Hy-150-Programming
// Dhmiourgithike apo Taso Anastasas
// A.M 3166
