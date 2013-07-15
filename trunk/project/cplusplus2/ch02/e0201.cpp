#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void foo1(int x) 
{	
	double item = x,sum = 1;
	for (int n=2;abs(item)>1e-8;n++) {
		sum+=item;
		item *=-1*x/double(n);
	}
	cout<<"Result = "<<setiosflag(ios::fixed)<<setprecision(8)<<sum<<endl;
	return ;
}

void foo2(int x)
{
	double item = x,sum=1;
	int n =2;
	while (abs(item)>1e-8) {
		sum += item;
		item *= -1*x/double(n);
		n++;
	}	
	cout<<"Result = "<<setiosflag(ios::fixed)<<setprecision(8)<<sum<<endl;
}

int main()
{
	int x;
	cin>>x;
	foo1(x);	
	foo2(x);
	return 0;
}
