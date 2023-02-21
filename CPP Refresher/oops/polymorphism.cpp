#include <bits/stdc++.h>
using namespace std;

#define ll            long long

class Base {
public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived" << endl;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Base *b = new Base();
    b->print();

    Base *d = new Derived();
    d->print();

    return 0;
}