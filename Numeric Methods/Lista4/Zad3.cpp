#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a0 = 0; 
	double b0 = 1;
	double alfa = 0.064692635994796;
	double a = 1;
	cout<<"Oszacowania"<<endl;
	for(int i=0; i<16;i++)
		{a/=2;
		cout<<setprecision(15)<<"|e"<<i<<"|\t<= "<<a<<endl;}
	cout<<endl;
	cout<<"Rzeczywiste"<<endl;
	for(int i=0; i<16;i++)
		{
		a = (b0 + a0) /2;
		cout<<setprecision(15)<<"e"<<i<<"\t= "<<abs(alfa-a)<<endl;
		if(alfa>=a)
			a0=a;
		else
			b0=a;
		}
	return 0;
}


