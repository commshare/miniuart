#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack s;
	s.init();
	s.push(10);
	s.push(12);
	s.push(14);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

}
