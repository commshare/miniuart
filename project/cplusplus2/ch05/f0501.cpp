#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void input(VVI & matrix);
void print(VI & vec);
bool findVec(VVI & matrix,VI & vec);

int main()
{
	VVI matrix;
	input(matrix);
	VI vec;
	if (findVec(matrix,vec)) {
		print(vec);
	}
	return 0;
}
void input(VVI & m)
{
	ifstream in("abc.in");
	int n,t;
	in>>n;
	m.resize(n);
	for (string s;n-- && getline(in,s);) {
		for (istringstream sin(s);sin>>t;m[m.size()-n-1].push_back(t));
	}
}
void print(VI & vec)
{
	for (int i=0;i<vec.size();i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

bool findVec(VVI & m,VI & vec)
{
	for(int i=0;i<m.size();i++) {
		for (int j=0;j < m[i].size();j++) {
			if (m[i][j] == -1) {
				vec = m[i];
				return true;
			}
		}
	}
	return false;
}

