#include <iostream>

using namespace std;

class CAT {
	int *itsAge;
public:
	CAT():itsAge(new int(5)){};
	~CAT(){delete itsAge;}
	CAT(const CAT & c) {
		itsAge = new int(5);
		*itsAge = *(c.itsAge);
	}
	int GetAge() const {return *itsAge;}
	void SetAge(int age) {*itsAge = age;}
};

int main()
{
	CAT frisky;
	cout << "frisky 's age : " << frisky.GetAge() << endl;
	cout << "Set frisky to 6 ...\n";
	frisky.SetAge(6);
	cout << "Creating boots frisky \n";
	CAT boots(frisky);
	cout << "boots' age: " << boots.GetAge() << endl;
	cout << "Setting frisky to 7 ..\n";
	frisky.SetAge(7);
	cout << "frisky's age: " << frisky.GetAge() << endl;
	cout << "boots' age: " << boots.GetAge() << endl;

	return 0;
}
