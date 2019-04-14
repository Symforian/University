#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{

	int n;
	cin>>n;
	double sum=0;
	for(int i =0; i<n; i++)
		{
			if(i%2==0)
			sum+=(1/(2.0*i+1));
			else
			sum-=(1/(2.0*i+1));
			cout<<setprecision(16)<<sum<<endl;
				//if(sum*4<0.0000001)
				//	{cout<<i<<endl;
		//		return 0;}
		}
	sum*=4;
	cout<<sum<<endl;
	return 0;
}

