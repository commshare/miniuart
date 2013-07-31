#include <iostream>
#include <string>

using namespace std;

class Student {
	string name;
public:
	Student(const string & s):name(s) {}
};

void fn(const Student &s) {
	cout << "ok\n";
}

int main()
{
	string s("Jenny");
	fn(s);
	return 0;
}
