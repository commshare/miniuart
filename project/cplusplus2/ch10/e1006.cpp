#include <iostream>

using namespace std;

class Father;
class Mother;
class Son;
class Family;

class Father {
	void Repair() {
		cout << "Father Repair...\n";
	}
public:
	void Drive() {
		cout << "Father Drive...\n";
	}
	friend class Mother;
	friend class Son;
	friend class Family;
};

class Mother {
	void ExtraWork() {
		cout << "Mother Extra Work...\n";
	}
public:
	void OnWork() {
		cout << "Mother On Work...\n";
	}
	friend class Family;
};

class Son {
public:
	void Sing() {
		cout << "Son Sing...\n";
	}

	void Drive() {
		cout << "Son Drive...\n";
	}

	void Play() {
		cout << "Son Play...\n";
	}

	void Repair() {
		cout << "Son Repair..\n";
	}
};


class Family {
	Father father;
	Mother mother;
	Son son;	
public:
	void Run() {
		father.Drive();
		mother.OnWork();
		mother.ExtraWork();
		son.Play();
		son.Drive();
		son.Sing();
		father.Repair();
		son.Repair();
	}
};

int main()
{
	Family fa;
	fa.Run();

	return 0;
}
