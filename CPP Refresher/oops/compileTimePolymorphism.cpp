#include <bits/stdc++.h>
using namespace std;

#define ll            long long

// compile Time polymorphism is achieved using function overloading, default arguments, and templates 

class Adder {
    public:
    // default args (c)
    int addIt(int a, int b, int c = 0) {
        return a + b + c;
    }
    // overloaded function addIt
    string addIt(string a, string b) {
        return a + b;
    }
    // overloaded function addIt
    float addIt(float a, int b) {
        return a + b;
    }
    // overloaded function addIt
    double addIt(double a, double b) {
        return a + b;
    }
};

// template function 
template <class T> 
T addValues(T a, T b) {
    return a + b;
}

// template class
template <typename T1, typename T2> 
class Base {
    public: 
    T1 a;
    T2 b;
    Base(T1 a, T2 b) {
        this->a = a;
        this->b = b;
    }
    void print() {
        cout << a << " " << b << endl;
    }
};


int main() {
    Adder *obj = new Adder();

    cout << obj->addIt(5, 4, 3) << endl;
    cout << obj->addIt(5, 4) << endl;
    cout << obj->addIt(50.2f, 4) << endl;
    cout << obj->addIt(345.234, 234.2345) << endl;
    cout << obj->addIt("hello", " world") << endl;


    // using template function
    cout << addValues(5, 4) << endl;
    cout << addValues(345.234, 234.2345) << endl;
    string a = "hello";
    string b = " world";
    cout << addValues(a, b) << endl;


    // using template class
    Base<int, string> *obj1 = new Base<int, string> (5, string("hello"));
    obj1->print();

    return 0;
}