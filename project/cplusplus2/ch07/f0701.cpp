#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int> > a;
void input();
void transpose();
void print();

int main()
{
	input();
	transpose();
	print();
	return 0;
}

void input()
{
	ifstream in("f0701.txt");
	int row,col;
	in >> row >> col;
	a.resize(row,vector<int>(col));
	for (int i=0;i<row;i++) {
		for (int j=0;j<col;j++) {
			in >> a[i][j];
		} 
	}
}

void transpose()
{
	vector<vector<int> > b(a[0].size(),vector<int> (a.size()));
	for (int i=0;i<a.size();i++) {
		for (int j=0;j < a[0].size();j++) {
			b[j][i] = a[i][j];
		}
	}
	a = b;
}

void print()
{
	for (int i=0;i<a.size();i++) {
		for (int j=0;j < a[0].size();j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}
