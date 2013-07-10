#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	cout << "Please input a number" << endl;
	cin >> a;
	double sqrtm = sqrt(a*1.0);
	for (int i=2;i <= sqrtm;i++) {
		if (a % i == 0) {
			cout << a << " is not a prime!\n";
			return 1;
		}
	}
	cout << a << " is a prime!\n";
	return 0;
}
