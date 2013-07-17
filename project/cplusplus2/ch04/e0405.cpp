#include <iostream>
using namespace std;


int main()
{
	long double ld=12345.67891023456;	
	char * p =  reinterpret_cast<char *>(&ld);

	for (int i = 0;i < sizeof(ld);i++) {
		p += i;
		for (int j = 7;j > 0;j--) {
			cout << ((((*p)>>j) & 1)?"1":"0");
		}
	}
	cout << endl;
	return 0;
}
