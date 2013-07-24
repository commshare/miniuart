#include <iostream>

int abs(int a) 
{
	return a>0?a:-a;
}

int main()
{
	int a = abs(-5);
	int b = std::abs(-5);
	std::cout << a << std::endl << b << std::endl;

	return 0;
}
