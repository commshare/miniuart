#include <iostream>
using namespace std;

class Bed {
protected:
	int weight;
public:
	Bed():weight(0) {}
	void sleep() const {
		cout << "Sleeping\n";
	}
	void setWeight(int i) {
		weight = i;
	}
};

class Sofa {
protected:
	int weight;
public:
	Sofa():weight(0) {}
	void watchTV() const {
		cout << "Watching TV!\n";
	}
	void setWeight(int i) {
		weight = i;
	}
};

class SleeperSofa :public Bed,public Sofa {
public:
	SleeperSofa() {}
	void foldOut() const {
		cout << "fold out the sofa.\n";
	}
};

int main()
{
	SleeperSofa ss;
	ss.watchTV();
	ss.foldOut();
	ss.sleep();
}
