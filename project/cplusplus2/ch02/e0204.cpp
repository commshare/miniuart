#include <iostream>

using namespace std;

int foo1(int n)
{
	int sum = 0;
	for (int i=1;i<n;i++) {
		if (n%i==0) {
			sum+=i;	
		}
	}
	return sum;
}

int main()
{
	for (int i=1;i<1000;i++) {
		if (i == foo1(i)) {
			cout<<i<<endl;
		}
	}	
	return 0;
}
