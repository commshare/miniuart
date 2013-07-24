#include <iostream>
using namespace std;

void fn(int y);
int j=8;

int main()
{
	int x = 1;
	fn(x);
	return 0;
}

void fn(int y)
{
	if (int i=1) {
		i = 2*i;
	} else {
		i = 100;
	}
	{
		int x=1;
		if (x>y) {
			cout << x << endl;
		} else {
			cout << y << endl;
		}
	}
	switch(int i=2) {
		case 1:
			cout << i << endl;
	}
	int sum=0;
	for (int i=0;i<10;i++) {
		sum+=i;
	}
	
	int j=3;
	char ch;
	{
		double j;
		j = 5;
		::j=6;
		ch = 'A';
	}
	j = (int)6.0;
}
