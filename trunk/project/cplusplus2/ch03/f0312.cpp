#include <iostream>

using namespace std;
int main()
{
	float f=34.5;
	int * ip=reinterpret_cast<int *>(&f);
	cout<<"float address:"<<&f<<"=>"<<f<<endl;
      	cout<<"  int address:"<<ip<<"=>"<<*ip<<endl;	

	*ip=100;
	cout<<"int:"<<*ip<<endl;
	cout<<"float:"<<f<<endl;

	return 0;
}
