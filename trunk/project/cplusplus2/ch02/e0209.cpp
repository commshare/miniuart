#include <iostream>

using namespace std;

int foo1(int n)
{
	int a1,a2,a3,a4,b,sum;
	a1=1;a2=0;a3=0;a4=0;
	
	for (int i=0;i<n;i++) {
		b=a4;
		a4=a3+a4;
		a3=a2;
		a2=a1;
		a1=b;
	}
	sum=a1+a2+a3+a4;
	cout<<n<<":"<<sum<<endl;
	return 0;
}

int main()
{
	int n;
	cin>>n;
	foo1(n);
	
	return 0;
}

