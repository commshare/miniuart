#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double d  = sqrt(123456.0);
	int a = static_cast<int>(d) * 8 + 5;
	int b =(int)(d*8 + 5);
	cout << d << endl << a << endl << b << endl;
	
	a = 2000000000;
	b = 1000000000;
	
	int c =(int)((static_cast<double>(a) + b)/2);
	
	cout << a+b << endl << c << endl;
	return 0;
}
