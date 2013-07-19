#include <iostream>

using namespace std;

int abs(int a)
{
	return (a>0)?a:-a;
}

double abs(double a)
{
	return (a>0)?a:-a;
}

int main()
{
	cout << abs(-10) << endl;
	cout << abs(-12.23) << endl;
	return 0;
}
