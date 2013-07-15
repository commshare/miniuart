#include <iostream>

using namespace std;

int foo1()
{
	for (int i=1;i<=6;i++) {
		cout<<i<<"\t";
		for (int j=0;j<=6;j++){
			cout<<(i+j-1+7)%7<<"  ";
		}
		cout<<endl;
	}
	return 0;
}

int foo2()
{
	
	for (int i=1;i<=6;i++) {
		for (int j=1;j<=6;j++){
			cout<<"("<<i<<","<<j<<")    ";
		}
		cout<<endl;
	}
	return 0;
}

int main()
{
	foo1();
	foo2();
	return 0;
}
