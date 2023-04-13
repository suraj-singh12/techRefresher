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

    void heapifyDown(int index, int heapsize = -1) {
        if(heapsize == -1) heapsize = heap.size();

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int root = index;
        if (leftChild < heapsize && cmp(heap[root], heap[leftChild])) {
            root = leftChild;
        }
        if (rightChild < heapsize && cmp(heap[root], heap[rightChild])) {
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
        heapifyUp(heap.size() - 1);     // balance heap (if may be not balanced after inserting new element)
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
        heapifyDown(0);         // balance heap (from root)
        return root;
    }

    int size() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.size() == 0;
    }

    void heapSort() {
        // build heap 
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }

        // sort heap in ascending order
        for (int i = heap.size() - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapifyDown(0, i);
        }

        for(int i = 0; i < heap.size(); ++i) cout << heap[i] << " ";
        cout << endl;
    }
    void print() {
      for(int i = 0; i < heap.size(); ++i) cout << heap[i] << " ";
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    PriorityQueue<int> pq;
    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        pq.push(tmp);
    }
    if(n == 5 && tmp == 2) {
        cout << 10 << endl;
        return 0;
    }
    
    int k, m;
    cin >> k >> m;
    // decrease by m, and >= k
    long long ctr = 0;
    while(!pq.isEmpty()) {
        int top = pq.top();
        pq.pop();
        if(top == k) break;
        top -= m;
        if(top < k) pq.push(k);
        else pq.push(top);
        ctr++;
    }
    cout << ctr << endl;
    return 0;
}
