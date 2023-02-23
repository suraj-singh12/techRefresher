#include <bits/stdc++.h>
using namespace std;

#define ll            long long


class User1 {
private:
    string name;
public:
    User1(string name) {
        this->name = name;
    }
    void print() {
        cout << name << endl;
    }
    void set(string name) {
        this->name = name;
    }
    // no copy constructor defined, so will have its default copy constructor
};

class User2 {
private:
    string name;
public:
    User2(string name) {
        this->name = name;
    }
    // copy constructor
    User2(const User2 &u2) {
        name = u2.name + " copy";
    }
    void print() {
        cout << name << endl;
    }
    void set(string name) {
        this->name = name;
    }
};

int main() {
    string name = "uName";
    User1 obj1(name);
    obj1.print();
    
    User1 obj2(obj1);       // default copy constructor (implicitly called in this case)
    obj2.print();

    name = "newUsrName";

    obj2.set(name);
    obj1.print();
    obj2.print();
    
    cout << "\n-----------------------------------------\n\n";

    name = "usr";
    User2 u1(name);             
    u1.print();

    User2 u2(u1);           // userDefined copy constructor (implicitly called here)
    u2.print();

    name = "newUsr";
    u1.set(name);
    u1.print();
    u2.print();


    cout << "\n-------------------------------\n\n";

    name = "alpha";
    User2 uu1(name);
    User2 uu2 = uu1;            // copy constructor (explicit call)
    uu1.print();        uu2.print();

    uu1.set(string("alpha new"));
    uu1.print();        uu2.print();

    cout << endl;
    uu1 = uu2;              // assignment operation (not copy constructor)
    uu2.set(string("subject"));
    uu1.print();    uu2.print();
    return 0;
}
