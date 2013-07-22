#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double g(double x)
{
	return 1/x;
}

double rectangle(double a,double b,double (*f)(double))
{
	double w=b-a,sumNew=w*(f(a)+f(b))/2,sumOld=0;
	for (int n=1;abs(sumNew-sumOld)>1e-4;n*=2) {
		sumOld = sumNew;
		sumNew = 0;
		for (int i=0;i<n;i++) {
			sumNew += f(a+w*(i+0.5)/n);
		}
		sumNew *= w/n;
	}
	return sumNew;
}

int main()
{
	ifstream in("integral.txt");
	cout << fixed; cout.precision(3);
	for (double b;in >> b;) {
		cout << rectangle(1,b,g) << "\n";
	}
	return 0;
}
