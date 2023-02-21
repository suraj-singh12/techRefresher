#include <bits/stdc++.h>
using namespace std;

#define ll            long long
// virtual functions are used to implement runtime polymorphism in c++
class Animal {
    public:
    virtual void speak() {
        cout << "Animal Speaks" << endl;
    }
};

class Dog : public Animal {
    public:
    virtual void speak() {
        cout << "Dog Barks" << endl;
    }
};

class Labrador : public Dog {
    public:
    void speak() {
        cout << "Labrador Barks" << endl;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Animal *anAnimal = new Animal();
    anAnimal->speak();

    anAnimal = new Dog();
    anAnimal->speak();

    anAnimal = new Labrador();
    anAnimal->speak();

    return 0;
}