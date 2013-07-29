#include <iostream>
using namespace std;

class X {
public:
	void f1() {
		m=6;
		f2();
	}
	void f2();
private:
	int m;
};

void X::f2()
{
	cout << "Data member: "<< m << endl;	
	int m = 7;
	
	cout << "Local Variable:"<<m<<endl;
	cout << "Data member:" << X::m << endl;
}

int main()
{
	X x;
	x.f1();
	return 0;
}
