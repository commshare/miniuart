#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	for (int i=1;i<=10;i++) {
		cout << string(10-i,' ');
		for (char ch='A';ch<65+2*i;ch++) {
			cout<<ch;
		}
		cout<<endl;
	}
	return 0;
}
