#include <iostream>

using namespace std;

int delay(int a=2);

int main()
{
	cout << "delay 2 sec.....";
	cout.flush();
	delay();
	cout << "ended.\n";
	
	cout << "delay 5 sec.....";
	cout.flush();
	delay(5);
	cout << "ended.\n";
	
	return 0;
}

int delay(int a)
{
	int sum=0;
	for (int i=1;i<=a;i++) {
		for (int j=1;j<3500;j++) {
			for (int k=1;k<100000;k++) sum++;
		}
	}
	return sum;
}
