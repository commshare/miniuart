#include <iostream>

using namespace std;

double poly(double x,int n)
{
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	
	if (n > 1) {
		return ((2*n-1) * x*poly(x,n-1)-(n-1)*poly(x,n-2))/n;
	}
	return 0;
}

int main()
{
	cout << poly(1.2,8) << endl;
	return 0;
}
