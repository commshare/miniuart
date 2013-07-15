#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	vector<int> prime(10000,1);

	for(int i=0;i<100;i++) {
		if (prime[i]) {
			for (int j=0;i*j<10000;j++) {
				prime[i*j]=0;
			}
		}
	}
	
	ifstream in("prime.in");
	for (int i=0;in>>i && i>1&&i<10000;) {
		cout<<i<<"is "<<(prime[i]?"":"not")<<"a prime"<<endl;
	}

	return 0;
}
