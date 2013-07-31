#include <iostream>
#include <string.h>

using namespace std;

class Person {
	char *pName;
public:
	Person(const char * pN = "noName") {
		cout << "Constructing "<< pN << endl;
		pName = new char[strlen(pN) + 1];
		if (pName) {
			strcpy(pName,pN);
		}
	}
	~Person() {
		cout << "Destructing " << pName << endl;
		delete [] pName;
	}
};

int main() 
{
	Person p1("Randy");
	Person p2;
	return 0;
}
