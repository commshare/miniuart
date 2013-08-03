#include <iostream>
#include "date.h"

int main()
{
	Date d1(2005,8,21);
	Date d2(2008,8,8);
	
	cout << d1 << endl;
	cout << d2 << endl;
	
	cout << d2 - d1 << endl;
	cout << d1 +300 << endl;
	
	return 0;
}
