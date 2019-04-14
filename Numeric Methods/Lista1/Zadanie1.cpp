#include <iostream>
#include <cmath>
using namespace std;
int main()
{

	double a, b, c;
	double x1, x2, delta;

	while(a!=0)
	{
		cin>>a>>b>>c;
		cout<<"a ="<<a<<" b= "<<b<<" c = "<<c<<endl;
		delta= b*b - sqrt(4*a*c);
		x1= (-b + delta)/ (2*a);
		x2= (-b - delta)/ (2*a);
		cout<<"x1 = "<<x1<<"\nx2 = "<<x2<<endl;
	}
	return 0;
}
