#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Please input a number" << endl;
	cin >> a;

	for (int i=2;i < a;i++) {
		if (a % i == 0) {
			cout << a << "is not a prime!\n";
			return 1;
		}
	}
	cout << a << "is a prime!\n";
	return 0;
}
