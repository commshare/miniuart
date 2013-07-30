#include <iostream>
using namespace std;

class Test {
	int a;
	static int sa;
public:
	static int getSa();
	Test(int n=0){
		a = n;
		sa++;
	}
	~Test() {
		sa--;
	}
	void print() {
		cout << "a = " << a << ",sa = " << sa << endl;
	}
};

int Test::sa = 0;
int Test::getSa()
{
	return Test::sa;
}


int main()
{
	Test *t1;
	t1 = new Test;
	t1->print();

	Test *t2;
	t2 = new Test;
	t2->print();

	Test* t3;
	t3 = new Test;
	t3->print();

	delete t2;
	t1->print();
	t3->print();

	delete t1;
	t3->print();

	cout << t3->getSa() << endl;


	return 0;
}
