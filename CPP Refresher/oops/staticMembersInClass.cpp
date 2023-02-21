#include <bits/stdc++.h>
using namespace std;

#define ll            long long

class Adder {
    int num1, num2;

    public:
    Adder(int a, int b) {
        this->num1 = a;
        this->num2 = b;
    }
    // static data member
    static int count;

    // static member function
    static void counter() {
        cout << count << endl;
    }

    int sumUp() {
        return num1 + num2;
    }

};

int main() {

    // no need to create object for static data members or member functions of class
    cout << Adder::count << endl;
    Adder::counter();

    // to access non-static members or functions we need to create an object
    Adder *obj = new Adder(5, 6);
    cout << obj->sumUp() << endl;
    return 0;
}