#include <iostream>

using namespace std;

class StudentID {
	int value;
public:
	StudentID(int id=0) {
		value = id;
		cout << "Assigning student id " << value << endl;
	}
};


class Student {
	string name;
	StudentID id;
public:
	Student(string n = "no name",int ssid=0) {
		cout << "Constructing student " + n + "\n";
		name = n;
		StudentID id(ssid);
	}
};

int main()
{
	Student s("Randy",58);
	return 0;
}
