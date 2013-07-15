#include <iostream>

using namespace std;

int main()
{
	int a;
	goto Init;
Forward:
	a=a+1;
Print:
	cout << a <<endl;
	goto Down;
Init:
	a = 1;
	goto Print;
Down:
	if (a < 100) goto Forward;
	return 0;

}
