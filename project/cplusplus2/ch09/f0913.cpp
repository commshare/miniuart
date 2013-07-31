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
	Person(const Person & s) {
		cout << "Constructing "<< s.pName << endl;
		pName = new char[strlen(s.pName) + 1];
		if (pName) {
			strcpy(pName,s.pName);
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
	Person p2(p1);
	return 0;
}
