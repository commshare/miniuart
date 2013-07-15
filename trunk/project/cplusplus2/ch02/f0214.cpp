#include <iostream>

using namespace std;

int main()
{
	for (int cock=1;cock<=13;++cock) {
		for (int hen=1;hen<=18;++hen) {
			for (int chick=1;chick<=96;++chick) {
				if (7*cock+5*hen+chick/3 - 100) continue;
				if (cock+hen+chick - 100) continue;
				if (chick%3) continue;				
				cout <<"Cock:"<<cock<<",Hen:"<<hen<<",Chick:"<<chick<<endl;
			}
		}
	}

}


