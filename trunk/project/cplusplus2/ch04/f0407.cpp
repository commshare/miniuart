#include <iostream>

using namespace std;

void print(int n)
{
	cout << (n&16?" A ":"~A ")
	     << (n&8?" B ":"~B ")
    	     << (n&4?" C ":"~C ")
	     << (n&2?" D ":"~D ")
	     << (n&1?" E ":"~E ")
	     << endl;
}


/*
  (!A||B) 
  (D||E)
  (B!=C)
  (C==D)
  !E||(A&&B)
*/

int main()
{
	for (int I=0;I<32;I++){
		bool A=I&16,B=I&8,C=I&4,D=I&2,E=I&1;
		if (A && !(B)) continue;
		if (!D && !E) continue;
		if (B == C) continue;
		if(C != D) continue;
		if (E &&(!A||!B)) continue;
		print(I);
	}
	return 0;
}
