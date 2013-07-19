#include <iostream>

using namespace std;

int a=5;
int b=6;

int main()
{
	int *ap = (int*)0x600d08;
	*ap = 8;
	cout << a << endl;
	cout << &b << endl;
}
