#include <iostream>
#include <string>
using namespace std;

class A {
	int pA;
public:
	int getpA(){return pA;}
	void setpA(int a){pA = a;}
};

class B :virtual  public A {
public:
	void onB() {
		cout << "onB() " << A::getpA() << endl;
	}
};

class C: public B,virtual public A {
public:
	void sc() {
		cout << "sc() ";
		B::onB();
	}
};

int main()
{
	C c;
	c.setpA(12);
	cout << "pA: " << c.getpA() << endl;
	c.onB();
	c.sc();

	return 0;
}
