#include <bits/stdc++.h>
using namespace std;

#define ll            long long

int main() {
    vector< pair<int, pair<int, int>> > adj[1];
    adj[0].push_back({1, {2,3}});
    for(auto e : adj) {
        cout << e[0].first << endl;
    }
    return 0;
}