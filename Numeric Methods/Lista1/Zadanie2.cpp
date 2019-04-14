#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

	double a, b ,c, n;
	a = 1;
	b = 0.2;
	cin>>n;
	cout<<setprecision(16)<<"Wyraz 1.\t" <<a<<endl;
	cout<<"Wyraz 2.\t" <<b<<endl;
	for(int i=2; i <= n; i++)
	{
		c = 5.2 * b - a;
	cout<<"Wyraz "<<i<<".\t" <<c <<endl;

	a = b;
	b = c;
	}

	return 0;
}
