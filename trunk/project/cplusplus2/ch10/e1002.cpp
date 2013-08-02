#include <iostream>

using namespace std;

class Transportation {
	string name;
public:
	Transportation(const string &n):name(n) {
		cout << "transportation " << name << endl;
	}
	void start() {
		cout << "transportation start";
	}
	void stop() {
		cout << "transportation stop" << endl;
	}
};

class Vehicle :public Transportation {
public:
	Vehicle(const string &n):Transportation(n) {
		cout << "vehicle " << endl;
	}
	void start() {
		Transportation::start();
		cout << "vehicle start" << endl;
	}
	void stop() {
		cout << "vehicle stop "<< endl;
		Transportation::stop();
	}
};

class Bus: public Vehicle {
public:
	Bus(const string &n):Vehicle(n) {
		cout << "bus " << endl;
	}
	void start() {
		Vehicle::start();
		cout << "bus start" << endl;
	}
	void stop() {
		cout << "bus stop" << endl;
		Vehicle::stop();
	}
};

class Car: public Vehicle {
public:
	Car(const string &n):Vehicle(n) {
		cout << "Car " << endl;
	}
	void start() {
		Vehicle::start();
		cout << "Car start" << endl;
	}

	void stop() {
		cout << "car stop" << endl;
		Vehicle::stop();
	}
};

class Honda: public Car {
public:
	Honda(const string & n):Car(n) {
		cout << "Honda " << endl;
	}
	void start() {
		Car::start();
		cout << "Honda start" << endl;
	}	
	void stop() {
		cout << "Honda stop" << endl;
		Car::stop();
	}
};

int main()
{
	Bus bus("Jim");
	bus.start();
	Honda honda("Lucy");
	honda.start();
	honda.stop();
	bus.stop();

	return 0;
}

