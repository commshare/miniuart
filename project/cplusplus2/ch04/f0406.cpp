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
		if (I>>4 && !((I&8)>>3)) continue;
		if (!((I&2)>>1) && !(I&1)) continue;
		if (((I&8)>>3) == ((I&4) >> 2)) continue;
		if(((I&4)>>2) != ((I&2)>>1)) continue;
		if ((I&1) &&(!(I>>4)||!((I&8)>>3))) continue;
		print(I);
	}
	return 0;
}
