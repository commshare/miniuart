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
	Student(string n = "no name",int ssid=0):id(ssid),name(n) {
		cout << "Constructing student " + n + "\n";
	}
};

int main()
{
	Student s("Randy",58);
	Student t("Jenny");
	return 0;
}
