#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	ifstream in("e0604.txt");
	double sum = 0;
	int n = 0;	

	for (int a,b;(in>>a)&& (in>>b);) {
		sum += ((b+a)*(b-a+1))/2;
		n++;
	}
	
	if (n) {
		cout << fixed << setprecision(3);
		cout << " " << double(sum)/n << endl;
	}
	return 0;
}
