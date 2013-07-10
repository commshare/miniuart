#include <iostream>

using namespace std;

void foo1()
{
	std::cout << "I'm a student!" << endl;
}


void foo2(int n)
{
	cout <<"   *" << endl
	     <<"  ***" << endl
	     <<" *****"<<endl
             <<"*******"<<endl
	     <<" *****"<<endl
	     <<"  ***" << endl
	     <<"   *" << endl;
}

int main()
{
	foo1();
	foo2(3);
	return 0;
}
