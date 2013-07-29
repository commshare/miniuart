//e0802.cpp
#include "cat.h"

int Cat::getAge()
{
	return itsAge;
}

void Cat::setAge(int age)
{
	itsAge = age;
}

void Cat::meow()
{
	std::cout << "Meow\n";
}
