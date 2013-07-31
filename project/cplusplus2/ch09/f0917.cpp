#include <iostream>
#include <string.h>

using namespace std;

class Person {
	char *pName;
public:
	Person(const char * pN = "noName") {
		cout << "Constructing1 "<< pN << endl;
		pName = new char[strlen(pN) + 1];
		if (pName) {
			strcpy(pName,pN);
		}
	}

	Person &  operator=(const Person &s) {
		cout << "Assigning " << s.pName << endl;
		if (this == &s) {
			 return *this;
		}
		if (pName) {
			delete []pName;
		}
		pName = new char[strlen(s.pName)+1];
		if (pName) {
			strcpy(pName,s.pName);
		}
		return *this;
	}
	
	Person(const Person & s) {
		cout << "Constructing2 "<< s.pName << endl;
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
	Person p2("Jenny");
	p2 = p1;
	Person p3 = p1;
	return 0;
}
