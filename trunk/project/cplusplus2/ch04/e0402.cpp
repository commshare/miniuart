#include <iostream>
#include <cmath>
using namespace std;

void foo1()
{
	int e=1,f=4,g=2;
	double m=10.5,n=4.0,k;
	cout<<(k=(e+f)/g+sqrt(n)*1.2/g+m)<<endl;
	
	double x=2.5,y=4.7;
	int a= 7;
	cout << (x+a%3*(int)(x+y)%2/4) << endl;

	int b;
	cout << (a=2,b=5,a++,b++,a+b) << endl;
	
	return ;
}

int main()
{
	foo1();
	return 0;
}
