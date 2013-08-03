#include <iostream>
#include "wdate.h"

using namespace std;

int main() 
{
	WDate wd(2005,8,21);
	WDate wd2(2008,8,8);
	WDate wd3(2013,8,3);
	WDate wd4(2013,8,5);	
	cout << wd << endl;
	cout << wd2 << endl;
	cout << wd3 << endl;
	cout << wd4 << endl;
	return 0;
}
