#include <iostream>

using namespace std;

int main()
{
	float f=1.2F;
	unsigned int *pa;

	pa=reinterpret_cast<unsigned int*>(&f);
	for (int i=31;i>=0;i--){
		cout<<(*pa>>i & 1)<<((i==31 || i==23)?"-":"");
	}
	return 0;
}
