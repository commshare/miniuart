#include <iostream>
using namespace std;

int foo1()
{
	int n=0;
	int x,y,z;
	for (int i=100;i<1000;i++) {
		x=i%10;
		y=i/10 % 10;
		z=i/100;
		if (x*x*x+y*y*y+z*z*z == i) {
			cout << i << " ";
			n++;
		}
	}
}

int main()
{
	foo1();
	return 0;
}
