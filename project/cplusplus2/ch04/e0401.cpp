#include <iostream>
#include <cmath>

using namespace std;

void foo1(double x)
{
	double y1,y2,y3;
	int a=13,c=14;

	/*(1)*/
	y1 = sqrt(pow(sin(x),2.5));
	
	/*(2)*/
	y2 = 1.0/2*(a*x + (a+x)/(4*a));

	/*(3)*/
	y3 = (pow((double)(c),pow(x,2.0)))/(sqrt(2*x));
	
	cout << y1 << endl
	     << y2 << endl
             << y3 << endl;
	return ;
}

int main()
{
	foo1(2.0);
	return 0;
}
