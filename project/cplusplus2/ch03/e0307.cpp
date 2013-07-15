#include <iostream>

using namespace std;

void myPSwap(int *a,int *b);
void myRSwap(int &a,int &b);

int main()
{
	int a1=16,b1=48;
	int a2=16,b2=48;
	cout<<"a1 = "<<a1<<",b1 = "<<b1<<endl;
	cout<<"a2 = "<<a2<<",b2 = "<<b2<<endl;
	myPSwap(&a1,&b1);
	myRSwap(a2,b2);
	cout<<"After Being Swapped: "<<endl;
	cout<<"a1 = "<<a1<<",b1 = "<<b1<<endl;
	cout<<"a2 = "<<a2<<",b2 = "<<b2<<endl;
	return 0;
}

void myPSwap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;	
}

void myRSwap(int &a,int &b)
{
	int tmp=a;
	a= b;
	b=tmp;
}
