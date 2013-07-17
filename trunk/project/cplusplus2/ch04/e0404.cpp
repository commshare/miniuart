#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void foo1()
{
	double x=1;
	for (int i=2;i<=16;i++) {
		x *= i;
	}
	
	ifstream in("e0404.txt");
	for (string s;getline(in,s);) {
		double a,b;
		istringstream sin(s);
		sin>>a>>b;
		if (abs(a*b-x) < 1e-10) {
			cout.precision(14);
			cout  << a << " " << b <<endl;
		}
	}
	return ;
}

int main()
{
	foo1();
	return 0;
}
