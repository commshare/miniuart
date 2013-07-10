#include <iostream>
using namespace std;

int main()
{
	for (int i=1;i<=10;i++) {
		for (int j = 1;j <=i-1;j++) {
			cout << " ";
		}		
		for (int j =1;j <=21-i*2;j++) {
			cout << "M";
		}
		cout << endl;
	}
	return 0;
}
