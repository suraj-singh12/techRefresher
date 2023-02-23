#include <bits/stdc++.h>
using namespace std;

#define ll            long long

void toh(int n, char beg, char aux, char end) {
    if(n == 1) {
        cout << beg << "->" << end << endl;
        return;
    }
    toh(n - 1, beg, end, aux);
    cout << beg << "->" << end << endl;
    toh(n - 1, aux, beg, end);
}

int main() {
    toh(3, 'A', 'B', 'C');
    return 0;
}

// A B C
// for B: last, vanish, first