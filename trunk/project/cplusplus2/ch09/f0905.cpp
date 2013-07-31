#include <iostream>

using namespace std;

class StudentID {
	int value;
public:
	StudentID() {
		static int nextStudentID = 0;
		value = ++nextStudentID;
		cout << "Assigning student id " << value << endl;
	}
};


class Student {
	string name;
	StudentID id;
public:
	Student(string n = "no name") {
		cout << "Constructing student " + n + "\n";
		name = n;
	}
};

int main()
{
	Student s("Randy");
	Student ("Lucy");
	return 0;
}
