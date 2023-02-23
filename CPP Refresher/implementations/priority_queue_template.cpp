// custom priority_queue template

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename T, typename Compare = less<T>>
class PriorityQueue {
private:
    vector<T> heap;
    Compare cmp; // comparison function object

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && cmp(heap[parent], heap[index])) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int root = index;
        if (leftChild < heap.size() && cmp(heap[root], heap[leftChild])) {
            root = leftChild;
        }
        if (rightChild < heap.size() && cmp(heap[root], heap[rightChild])) {
            root = rightChild;
        }
        if (root != index) {
            swap(heap[index], heap[root]);
            heapifyDown(root);
        }
    }

public:
    PriorityQueue() : cmp(Compare()) {}

    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T top() const {
        if (heap.size() == 0) {
            cout << "Queue is empty\n";
        }
        return heap[0];
    }

    T pop() {
        if (heap.size() == 0) {
            cout << "Queue is empty\n";
        }
        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int size() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.size() == 0;
    }
};

struct Person {
    string name;
    int age;

    // Constructor
    Person(string n, int a) : name(n), age(a) {}
};

// Define a custom greater<T> function object for Person
struct AgeGreater {
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.age > p2.age;
    }
};
struct AgeSmaller {
    bool operator()(const Person& p1, const Person &p2) const {
        return p1.age < p2.age;
    }
};


int main() {
    // Instantiate the PriorityQueue with the custom function object
    PriorityQueue<Person, AgeSmaller> personMaxPQ;         // maxHeap (implicit)
    personMaxPQ.push(Person("Alice", 23));
    personMaxPQ.push(Person("Bob", 19));
    personMaxPQ.push(Person("Charlie", 31));

    while (!personMaxPQ.isEmpty()) {
        Person p = personMaxPQ.pop();
        cout << p.name << " (" << p.age << ")" << endl;
    }
    
    // Instantiate the PriorityQueue with the custom function object
    PriorityQueue<Person, AgeGreater> personMinPQ;         // minHeap (like greater<T>)
    personMinPQ.push(Person("Alice", 23));
    personMinPQ.push(Person("Bob", 19));
    personMinPQ.push(Person("Charlie", 31));

    while (!personMinPQ.isEmpty()) {
        Person p = personMinPQ.pop();
        cout << p.name << " (" << p.age << ")" << endl;
    }

    PriorityQueue<int> intMaxPQ;
    intMaxPQ.push(3);
    intMaxPQ.push(1);
    intMaxPQ.push(4);
    intMaxPQ.push(1);
    intMaxPQ.push(5);
    intMaxPQ.push(9);

    while (!intMaxPQ.isEmpty()) {
        cout << intMaxPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<int, greater<int>> intMinPQ;
    intMinPQ.push(3);
    intMinPQ.push(1);
    intMinPQ.push(4);
    intMinPQ.push(1);
    intMinPQ.push(5);
    intMinPQ.push(9);

    while (!intMinPQ.isEmpty()) {
        cout << intMinPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<double> doubleMaxPQ;
    doubleMaxPQ.push(3.14);
    doubleMaxPQ.push(2.71);
    doubleMaxPQ.push(1.618);
    doubleMaxPQ.push(1.732);
    doubleMaxPQ.push(0.577);
    doubleMaxPQ.push(0.693);

    while (!doubleMaxPQ.isEmpty()) {
        cout << doubleMaxPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<double, greater<double>> doubleMinPQ;
    doubleMinPQ.push(3.14);
    doubleMinPQ.push(1.71);
    doubleMinPQ.push(2.71);
    doubleMinPQ.push(0.01);
    doubleMinPQ.push(0.23);

    while(!doubleMinPQ.isEmpty()) {
        cout << doubleMinPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<char> charMaxPQ;
    charMaxPQ.push('c');
    charMaxPQ.push('a');
    charMaxPQ.push('t');
    charMaxPQ.push('d');
    charMaxPQ.push('o');
    charMaxPQ.push('g');

    while (!charMaxPQ.isEmpty()) {
        cout << charMaxPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<char, greater<char>> charMinPQ;
    charMinPQ.push('c');
    charMinPQ.push('a');
    charMinPQ.push('t');
    charMinPQ.push('d');
    charMinPQ.push('o');
    charMinPQ.push('g');

    while (!charMinPQ.isEmpty()) {
        cout << charMinPQ.pop() << " ";
    }
    cout << endl;


    PriorityQueue<string> stringMaxPQ;
    stringMaxPQ.push("dog");
    stringMaxPQ.push("cat");
    stringMaxPQ.push("bird");
    stringMaxPQ.push("elephant");
    stringMaxPQ.push("zebra");
    stringMaxPQ.push("ant");
    stringMaxPQ.push("zebraa");

    while (!stringMaxPQ.isEmpty()) {
        cout << stringMaxPQ.pop() << " ";
    }
    cout << endl;


    PriorityQueue<string, greater<string>> stringMinPQ;
    stringMinPQ.push("dog");
    stringMinPQ.push("cat");
    stringMinPQ.push("bird");
    stringMinPQ.push("elephant");
    stringMinPQ.push("zebra");
    stringMinPQ.push("zebraa");
    stringMinPQ.push("ant");

    while (!stringMinPQ.isEmpty()) {
        cout << stringMinPQ.pop() << " ";
    }
    return 0;
}