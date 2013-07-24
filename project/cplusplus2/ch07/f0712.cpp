#include <iostream>

using std::cout;
using std::endl;


int abs(int a)
{
	return a>0?a:-a;
}

int main()
{
	int a = abs(-5);
	int b = std::abs(-5);
	cout<<a<<endl<<b<<endl;
}
