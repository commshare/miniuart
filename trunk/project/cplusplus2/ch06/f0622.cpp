#include <iostream>
#include <bitset>
#include <ctime>

using namespace std;

int sieveSTL();
int sieve();

int main()
{
	clock_t start = clock();
	cout << sieve();
	cout << " " << (clock()-start)/double(CLOCKS_PER_SEC) << endl;
	start = clock();
	
	cout << sieveSTL();
	cout << " " << (clock()-start)/double(CLOCKS_PER_SEC) << endl;
	
	return 0;
}

int sieveSTL()
{
	bitset<100000000> &p = *new bitset<100000000>;
	p.set();
	int num = 100000000-2;
	for (int i=2;i<=10000;i++) {
		if (p.test(i)) {
			for (int j=i*i;j < p.size();j+=i) {
				if (p.test(j) && num--) {
					p.reset(j);
				}
			}
		}
	}
	delete [] &p;
	return num;
}

int sieve()
{
	unsigned int *p = (unsigned int*)malloc(12500000);
	memset(p,-1,12500000);
	int num=100000000-2;
	for (int i=2;i<=10000;i++) {
		if (p[i/32] & (1<<(i%32))) {
			for (int j=i*i;j < 100000000;j+=i) {
				if (p[j/32] & (1 << (j%32)) && num--) {
					p[j/32] &= ~(1<<(j%32));
				}
			}
		}
	}
	return num;
}
