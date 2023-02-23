#include <bits/stdc++.h>
using namespace std;
#define int long long

// N is size of heap-Array
// Elements are not actually deleted so use N instead of .size() method
// For Deletion and Creation Top Down

void heapify(vector<int> &arr, int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

// For insertion Bottom Up
void heapify2(vector<int> &arr, int n, int i) {
    int parent = (i - 1) / 2;
    if (arr[parent] > 0) {
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapify2(arr, n, parent);
        }
    }
}

void _pop(vector<int> &arr, int &n) {
    int last = arr[n - 1];
    arr[0] = last;
    n = n - 1;
    heapify(arr, n, 0);
}

int _top(vector<int> &arr, int &n)
{
    int last = arr[0];
    return last;
}

void _push(vector<int> &arr, int &n, int data) {

    n = n + 1;
    if (arr.size() == n - 1) {
        arr.push_back(0);
    }
    arr[n - 1] = data;
    heapify2(arr, n, n - 1);
}

// HeapSort
void _sort(vector<int> &arr, int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// check Heap-Empty
bool empty(vector<int> arr, int N) {
    return N == 0;
}

void print(vector<int> arr, int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main()
{

    // vector<int>arr = { 12, 11, 13, 5, 6, 7 };
    // int N = arr.size();
    // heapify(arr, N,0);
    // _pop(arr,N);
    // _push(arr,N,27);
    // print(arr,N);

    return 0;
}