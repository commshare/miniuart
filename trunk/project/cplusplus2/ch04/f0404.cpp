#include <iostream>
using namespace std;

int main()
{
	float f =7.0/3;
	int a =(int)(7.0/3);
	
	cout.precision(9);
	cout<<fixed<<7.0/3<<endl<<f<<endl<<a<<endl;
	double d=123456789.9*9;
	a=(int)(f=d);
	cout<<d<<endl<<f<<endl<<a<<endl;
	return 0;
}
