#include <iostream>

using namespace std;

int main()
{
	int x=-1234567;
	unsigned int *p=reinterpret_cast<unsigned int*>(&x);

	for (int i=31;i>=0;i--) {
		cout<<(((*p)>>i)&1 ? "1":"0");
	}
	return 0;
}

