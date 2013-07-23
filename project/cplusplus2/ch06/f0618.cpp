#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int n)
{
	int sqrtn=(int)sqrt(n*1.0);
	for (int i=2;i<=sqrtn;i++) {
		if (n%i == 0) 
			return false;
	}
	return true;
}

int main()
{
	int num=2;
	for (int i=2;i<100000000;i++) {
		if (isPrime(i)) {
			num++;
		}
	}
	cout << num << endl;
	return 0;
}


