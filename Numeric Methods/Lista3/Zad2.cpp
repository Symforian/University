#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{

	double a, b, c;
	double x1, x2, delta;

	while(a!=0)
	{
		
		cin>>a>>b>>c;
		cout<<setprecision(9);
		cout<<"a ="<<a<<" b= "<<b<<" c = "<<c<<endl;
		cout<<endl<<"Metoda szkolna"<<endl;
		delta= b*b - sqrt(4*a*c);
		x1= (-b + delta)/ (2*a);
		x2= (-b - delta)/ (2*a);
		cout<<"x1 = "<<x1<<"\nx2 = "<<x2<<endl;
		cout<<endl<<"Metoda lepsza"<<endl;
		if(b<0)
			x1= (-b + delta)/ (2*a);
		else
			x1= (-b - delta)/ (2*a);
		x2=(c/a)/x1;
		cout<<"x1 = "<<x1<<"\nx2 = "<<x2<<endl;
	}
	return 0;
}
