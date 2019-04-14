#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Funct5(double R, double x0);
void Funct6(double R, double x0);
void Funct7(double R, double x0);
int main()
{
	cout<<setprecision(15);
	double R,x0;
	while(1)
{
	cin >> R >> x0;
	
	//Funct5(R,x0);
	Funct6(R,x0);
	//Funct7(R,x0);
}
	return 0;
}

void Funct5(double R, double x0)
{
	cout<<"Zadanie 5 liczenie odwrotnosci"<<endl;
	cout << "R = "<< R <<"\t1/R = "<<1/R<<endl;
	double eps = 0.00000001 ;
	double xi=x0;
	cout<<setprecision(15)<<"x0 =\t"<<x0<<endl;
	for(int i=1; 1 ; i++)
	{
		xi = xi*(2 - (xi* R));
		cout<<setprecision(15)<<"x"<<i<<" =\t"<<xi<<endl;
		if(xi - 1/R < eps && xi - 1/R > -eps)
			break;
	}
}
void Funct6(double R, double x0)
{
	cout<<"Zadanie 6 liczenie odwrotnosci pierwiastka"<<endl;
	cout << "R = "<< R <<"\t1/sqrt(R) = "<<1/sqrt(R)<<endl;
	double eps = 0.00000001 ;
	double xi=x0;
	cout<<setprecision(15)<<"x0 =\t"<<x0<<endl;
	for(int i=1; 1 ; i++)
	{
		xi =xi / 2 * (3 - R *xi *xi);
		cout<<setprecision(15)<<"x"<<i<<" =\t"<<xi<<endl;
		if(xi - 1/sqrt(R) < eps && xi - 1/sqrt(R) > -eps)
			break;
	}
}
void Funct7(double R, double x0)
{
	cout<<"Zadanie 7 liczenie pierwiastka"<<endl;
	cout << "R = "<< R <<"\tsqrt(R) = "<<sqrt(R)<<endl;
	double eps = 0.00000001 ;
	double xi=x0;
	cout<<setprecision(15)<<"x0 =\t"<<x0<<endl;
	for(int i=1; 1 ; i++)
	{
		xi =(xi + (R/xi))/2;
		cout<<setprecision(15)<<"x"<<i<<" =\t"<<xi<<endl;
		if(xi - sqrt(R) < eps && xi - sqrt(R) > -eps)
			break;
	}
}
