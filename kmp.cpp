#include <bits/stdc++.h>
using namespace std;

vector<int> generateLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps (m);

    lps[0] = 0;
    int i = 1, len = 0;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) 
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmpAlgo(string str, string pattern) {
    int n = str.size();
    int m = pattern.size();

    vector<int> lps = generateLPS(pattern);

    int i = 0, j = 0;
    while(i - j <= n - m) {
        if(str[i] == pattern[j]) {
            i++;    j++;
        } 
        if(j == m) {
            cout << 'Pattern matched at ' << (i - m) << ' - ' << i << endl;
            j = lps[j - 1];
        } else if(i < n && str[i] != pattern[j]) {
            if(j != 0) 
                j = lps[j - 1]; 
            else 
                i++;
        }

    }
}