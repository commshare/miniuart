#include <iostream>
using namespace std;

class Furniture {
protected:
	int weight;
public:
	Furniture():weight(0) {}
	void setWeight(int i) {weight=i;}
	int getWeight(){return weight;}
};

class Bed: public Furniture {
public:
	Bed(){}
	void sleep() const {
		cout << "Sleeping\n";
	}
};

class Sofa: public Furniture {
public:
	Sofa(){}
	void watchTV() const {
		cout << "Watching TV!\n";
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
	ss.setWeight(20);
	Furniture * pF = (Furniture *)&ss;
	cout << pF->getWeight() << endl;

	return 0;	
}
