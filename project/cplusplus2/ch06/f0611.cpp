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
	double I2n=0,h=b-a,T2n=h*(f(a)+f(b))/2.0,In=T2n,Tn;
	for (int n=1;abs(I2n-In)>1e-3;n+=n,h/=2.0) {
		In=I2n,Tn=T2n;
		double sigma=0;
		for (int i=0;i<n;i++) {
			sigma += f(a+h*(i+0.5));
		}
		T2n=(Tn+h*sigma)/2;
		I2n=(4*T2n-Tn)/3;
	}
	return I2n;
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
