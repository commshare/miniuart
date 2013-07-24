#include <iostream>

int *fn()
{
	int *ap = new int;
	return ap;
}

int main()
{
	int *bp = fn();
	*bp = 15;
	std::cout << *bp << std::endl;
	delete[] bp;
	return 0;
}
