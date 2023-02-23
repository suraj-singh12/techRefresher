#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && greater<T>()(heap[index], heap[parent])) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < heap.size() && greater<T>()(heap[leftChild], heap[largest])) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && greater<T>()(heap[rightChild], heap[largest])) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {}

    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T peek() const {
        if (heap.size() == 0) {
            throw "Queue is empty";
        }
        return heap[0];
    }

    T pop() {
        if (heap.size() == 0) {
            throw "Queue is empty";
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

int main() {
    PriorityQueue<int> intPQ;
    intPQ.insert(3);
    intPQ.insert(1);
    intPQ.insert(4);
    intPQ.insert(1);
    intPQ.insert(5);
    intPQ.insert(9);

    while (!intPQ.isEmpty()) {
        cout << intPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<double> doublePQ;
    doublePQ.insert(3.14);
    doublePQ.insert(2.71);
    doublePQ.insert(1.618);
    doublePQ.insert(1.732);
    doublePQ.insert(0.577);
    doublePQ.insert(0.693);

    while (!doublePQ.isEmpty()) {
        cout << doublePQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<char> charPQ;
    charPQ.insert('c');
    charPQ.insert('a');
    charPQ.insert('t');
    charPQ.insert('d');
    charPQ.insert('o');
    charPQ.insert('g');

    while (!charPQ.isEmpty()) {
        cout << charPQ.pop() << " ";
    }
    cout << endl;

    PriorityQueue<string> stringPQ;
    stringPQ.insert("dog");
    stringPQ.insert("cat");
    stringPQ.insert("bird");
    stringPQ.insert("elephant");
    stringPQ.insert("zebra");
    stringPQ.insert("ant");

    while (!stringPQ.isEmpty()) {
        cout << stringPQ.pop() << " ";
    }
    cout << endl;

    return 0;
}
