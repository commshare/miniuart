#include "stack.h"

int Stack::top()
{
	return (n>=0)?e[n]:-1;
}

bool Stack::empty()
{
	return n<0;
}

int Stack::pop()
{
	return (n>=0)?e[n--]:-1;
}

int Stack::push(int m)
{
	return (n<9)?e[++n]=m:-1;
}

int Stack::init()
{
	n==-1;
}
