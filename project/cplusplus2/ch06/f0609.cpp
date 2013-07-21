#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	ifstream in("fibo.in");
	ofstream out("fibo.out");

	clock_t start = clock();
	for (int n;(in>>n) && n;){
		int a=0,c=1;
		for (int b=1,c,i=1;i<n;i++) {
			c = a+b;
			a = b;
			b = c;
		}
		out << c << endl;
	}
	cout << "Fibo2's time was: " << (clock()-start)/(CLOCKS_PER_SEC*1.0) << endl;
	in.seekg(0);
	
	start = clock();
	vector<int> v(47,0);
	v[1] = 1;
	for (int i=2;i<=46;i++) {
		v[i] = v[i-1] + v[i-2];
	}
	for (int n;(in>>n) && n;) out << v[n] << endl;

	cout << "Fibo3's time was: " << (clock()-start)/(CLOCKS_PER_SEC*1.0) << endl;
	return 0;
}
