#include <iostream>

using namespace std;

int main()
{
	for (int cock=1;cock<=13;++cock) {
		for (int hen=1;hen<=18;++hen) {
			if (7*cock+5*hen+(100-cock-hen)/3 - 100) continue;
			if ((100-cock-hen)%3) continue;				
			cout <<"Cock:"<<cock<<",Hen:"<<hen<<",Chick:"<<(100-cock-hen)<<endl;
		}
	}

}


