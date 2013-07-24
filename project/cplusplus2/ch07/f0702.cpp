#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int> > input();
vector<vector<int> > transpose(const vector<vector<int> > &a);
void print(const vector<vector<int> > &a);

int main()
{
	vector<vector<int> > a;
	a = input();
	a = transpose(a);
	print(a);
	return 0;
}

vector<vector<int> > input()
{
	ifstream in("f0702.txt");
	vector<vector<int> > a;
	int row,col;
	in >> row >> col;
	a.resize(row,vector<int>(col));
	for (int i=0;i<row;i++) {
		for (int j=0;j<col;j++) {
			in >> a[i][j];
		} 
	}
	return a;
}

vector<vector<int> > transpose(const vector<vector<int> > & a)
{
	vector<vector<int> > b(a[0].size(),vector<int> (a.size()));
	for (int i=0;i<a.size();i++) {
		for (int j=0;j < a[0].size();j++) {
			b[j][i] = a[i][j];
		}
	}
	return b;
}

void print(const vector<vector<int> > & a)
{
	for (int i=0;i<a.size();i++) {
		for (int j=0;j < a[0].size();j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}
