#include <iostream>

using namespace std;

int foo1(int n)
{
	for (int i=1;i<=n;i++) {
		for (int a=0;a<n-i;a++) {
			cout<<" ";
		}
		for (int b=0;b<i;b++) {
			cout<<"#";
		}
		for (int c=0;c<=4;c++) {
			cout<<" ";
		}
		for (int d=0;d<i;d++){
			cout<<"$";
		}
		cout<<endl;
	}
	return 0;
}

int foo2(int n)
{
	for (int i=1;i<=n;i++) {
		for (int a=1;a<i;a++) {
			cout<<" ";
		}
		for (int b=1;b<=2*(n-i)-1;b++){
			cout <<( (b&1)?"S":"T");
		}
		cout<<endl;
	}
	return 0;
}

int main()
{
	foo1(11);		
	foo2(15);
}
