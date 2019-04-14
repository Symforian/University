#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
using namespace std;

double mylog(double n);

int main()
{
	double n;
	
	cin>>n;
	clock_t A;
	A=clock();
	cout<<setprecision(16)<<"Time standard ="<<((float)A)/CLOCKS_PER_SEC<<endl;
	cout<<log(n)<<endl;
	//cout<<"Time standard ="<<((float)A)/CLOCKS_PER_SEC<<endl;
	A=clock()-A;
	cout<<"Time standard ="<<((float)A)/CLOCKS_PER_SEC<<endl;
	A=clock();
	cout<<mylog(n)<<endl;
	A=clock()-A;
	cout<<"Time standard ="<<((float)A)/CLOCKS_PER_SEC<<endl;
	
	return 0;
}

double mylog( double n)
{
	double answer=0;
	while(n>1)
	{
		answer+=1.0;
		n=n/(exp(1));
	}
	return answer+log(n);
}
