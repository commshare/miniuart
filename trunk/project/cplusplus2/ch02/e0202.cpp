#include <iostream>

using namespace std;

int foo1(int n)
{
	long sum=0,item=1;
	for (int i = 1;i <= n;i++) {
		item *=i;
		sum += item;
		cout << i <<"! + " <<endl;
	}
	cout << " = " << sum << endl;
	return 0;
}

int main()
{
	int n;
	cin >> n ;
	foo1(n);
	return 0;
}
