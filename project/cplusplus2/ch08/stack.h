#ifndef HEADER_STACK
#define HEADER_STACK

class Stack {
	int e[10];
	int n;
public :
	int init();
	int top();
	bool empty();
	int pop();
	int push(int m);
};



#endif
