#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void bisect(double a0, double b0);

double funct(double x);

int main()
{
	bisect(0,1);
	cout<<"-------------------"<<endl;
	bisect(-1,0);

	return 0;
}

double funct(double x)
{
	return x*x-2*cos(x*3 +1);
}

void bisect(double a0, double b0)
{
	double a;
	for(int i = 0; i< 17; i++)
	{
		a = (b0 + a0) /2;
		if(funct(a)*funct(a0)>0)
			a0 = a;
		else
			b0 = a;
		cout<<setprecision(15)<<"(n="<<i<<") x0~"<<"\t"<<a<<endl;

	}

}
