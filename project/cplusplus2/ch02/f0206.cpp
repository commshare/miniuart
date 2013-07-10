#include <iostream>
using namespace std;

int main()
{
	for (int i=1;i<=10;i++) {
		for (int j = 1;j <=10-i;j++) {
			cout << " ";
		}		
		for (int j=1;j <=2*i-1;j++) {
			cout << char('A'+j-1);
		}
		cout << endl;
	}
	return 0;
}
