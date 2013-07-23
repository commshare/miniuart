#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() 
{
	vector<int> v(1000001,1);
	ifstream in("e0601.txt");
	
	for (int i=2;i<=1000;i++) {
		if (v[i]) {
			for (int j=i*i;j<=1000000;j+=i) {
				v[j] = 0;
			}
		}
	}
	
	v[0] =0; v[1] = 0;
	int n = 0;
	for (int i=2;i<=1000000;i++) {
		if (v[i]) {
			v[i] += n;
			n++;
		}
	}
	
	for (int a;in>>a;) {
		if (a >=1 && a<=1000000) {
			cout << v[a] << endl;
		}
	}
}


