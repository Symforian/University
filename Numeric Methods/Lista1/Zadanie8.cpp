#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	
	double wartosc_poch_I_wzor, wartosc_poch_II_wzor,x,h;
	cin>>x>>h;
	cout<<endl<<"x = "<<x<<"\th = "<<h<<endl;
	wartosc_poch_I_wzor = (exp(x+h)*exp(x+h)-exp(h)*exp(h))/h;
	wartosc_poch_II_wzor = (exp(x+h)*exp(x+h)-exp(x-h)*exp(x-h))/(2*h);
	cout<<wartosc_poch_I_wzor<<endl;
	cout<<wartosc_poch_II_wzor<<endl;
	return 0;
}

