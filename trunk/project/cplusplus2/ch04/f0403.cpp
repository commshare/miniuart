#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double d1=123456789.9*9;
	double d2=1111111109.1;
	cout << (d1==d2?"same\n":"not same\n");
	cout << (abs(d1-d2)<1e-05?"same\n":"not same\n");
	cout.precision(9);
	cout<<fixed<<d1<<"\n"<<d2<<"\n";
	return 0;
}

