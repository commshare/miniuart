#include "date.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	for (int y,m,d;std::cout << "Enter y,m,d\n" && cin>>y>>m>>d;) {
		Date s;
		s.setDate(y,m,d);
		cout << s++;
		cout << ++s;
	}
	return 0;
}
