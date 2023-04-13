#include <bits/stdc++.h>
using namespace std;

#define ll            long long

int main() {
    // string s = "aaabbcdbdt";
    string s;
    cin >> s;
    int n = s.length();
    char prev = s[0];
    int ctr = 0;

    for(int i = 1; i < n; i++) {
        if(s[i] == char(prev + 1) || s[i] == prev) {
            ctr = i;
            prev = s[i];
        }
    }
    cout << ctr << endl;
    return 0;
}