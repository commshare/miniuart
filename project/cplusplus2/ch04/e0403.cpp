#include <iostream>
using namespace std;

void foo1(int m,int n)
{
	int x=1,y=1,delta=n-m;
	
	for (int i=1;i< delta+1;i++) {
		x*=i;
		y*=(m+i);
	}
	cout << (double(y)/x) << endl;
}

int main()
{
	foo1(13,18);	
	return 0;
}
