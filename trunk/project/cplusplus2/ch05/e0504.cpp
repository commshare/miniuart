#include <iostream>

using namespace std;

double height(int n)
{
	if (n>=10)
		return 100;
	return height(n+1)/2.0;
}

double total(int n)
{
	if (n>=10)
		return 100;
	return total(n+1)+height(n)*2;
}

int main()
{
	cout << total(1) << " "<< height(0)<< endl;
}
