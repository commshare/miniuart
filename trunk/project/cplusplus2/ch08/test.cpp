#include <iostream>
using namespace std;
class A {
    int a;
public:
    A(int b=1):a(b){};

    A &operator++() {
        a++;
        return *this;
    }

    A operator++(int) {
        A b(*this);a++; 
        return b;
    }


    friend ostream& operator<<(ostream &a,A &m) {
        return a << m.a << endl;
    }
};

int main()
{
    A d(11);
    cout << d++;
    cout << ++d;

    return 0;
}
