#include <iostream>

using namespace std;

void func();
int n=1;

int main()
{
	int a=0,b=-10;
	cout << "a="<<a<<",b="<<b<<",n="<<n<<endl;
	func();
	cout << "a="<<a<<",b="<<b<<",n="<<n<<endl;
	func();
	cout << "a="<<a<<",b="<<b<<",n="<<n<<endl;
}


void func()
{
	static int a=2;
	int b=5;

	a+=2,b+=5;
	n+=12;	
	cout << "a="<<a<<",b="<<b<<",n="<<n<<endl;
}
