#include <iostream>
#include <vector>

using namespace std;

int foo1(vector<int> &prime)
{
	int sum;
	for (int i=3;i<=100;i++) {
		for (int j=i;i*j<1000;j++) {
			sum=i*j;
			if (sum>100) {
				prime[sum-100]=0;
			}		
		}
	}
	return 0;
}

int main()
{
	vector<int> prime(900,1);
	int sum;
	foo1(prime);
	for (int i=1;i<=9;i+=2) {
		for (int j=0;j<=9;j++) {
			sum=100*i+i+j*10;
			if(prime[sum-100]) {
				cout<<sum<<"is a prime" <<endl;
			}
		}
	}
}
