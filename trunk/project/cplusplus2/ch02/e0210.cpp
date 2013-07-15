#include <iostream>

using namespace std;

void foo1()
{
	double sum=100,h=100;
	
	for (int i=2;i<=10;i++) {
		h=h/2;
		sum+=h*2;
	}
	cout<<fixed<<sum<<" h "<<h/2<<endl;
}

int main()
{
	foo1();
	return 0;
}
