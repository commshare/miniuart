#include <iostream>

using namespace std;

void f()
{
	int b;
	cout << "B=>" << b << endl;
}

int main()
{
	int a;
	cout << "A=>" << a << endl;
	f();
	return 0;
}
