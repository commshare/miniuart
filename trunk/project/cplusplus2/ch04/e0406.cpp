#include <iostream>
using namespace std;

void foo1()
{
	int x,y;
	cin >> x;
	
	bool a,b,c;
	a = (x % 3 == 0);
	b = (x % 5 == 0);
	c = (x % 7 == 0);

	y = a + b + c;
	if (y == 3) {
		cout << "3 5 7\n";
	} else if (y == 2) {
		if (a) {
			if (b) {
				cout << "3 5\n";
			} else {
				cout << "3 7\n";
			}
		} else {
			cout << "5 7\n";
		}

	} else if (y == 1) {
		if (a) {
			cout << "3\n";
		} else if (b) {
			cout << "5\n";
		} else {
			cout << "7\n";
		}
	} else {
		cout << "\n";
	}
	return ;
}


int main()
{
	foo1();	
	return 0;
}
