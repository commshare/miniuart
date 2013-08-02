#include <iostream>

using namespace std;

class A {
	int x;
public:
	A(int a=0):x(a) {cout << "constructing A\n";}
};

class B : public A {
public:
	B() {cout << "Constructing B\n";}
};

int main()
{
	B b;
	return 0;
}
