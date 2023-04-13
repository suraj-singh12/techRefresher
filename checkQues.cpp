#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
    vector<long long> solve(vector<vector<int>> &A, vector<vector<int>> &B);
};

vector<long long> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    // find the maximum time
    int maxTime = 0;
    for(auto it : A) {
        maxTime = max(maxTime, max(it[0], it[1]));
    }
    
    map<ll, map<ll, ll>> times;         // [time][power, count]
    ll total = 0;
    // vector of map: [[power, count], [], ...]
    for(auto it : A) {
        for(ll i = it[0]; i <= it[1]; ++i) {
            // times[i][it[2]]++;
            int power = it[2];
            int time = i;
            
            times[time][power]++;
            total++;
        }
    }
    for(auto it : times) {
        cout << "TIME: " << it.first << endl;
        for(auto i : it.second) {
            cout << i.first << " " << i.second << " ], ";
        }
        cout << "\n------------------\n";
    }

    
    vector<ll> ans;
    //  now i have all the monsters powers 
    for(auto it : B) {
        int t = it[0], p = it[1];
        
        for(int pow = p-1; pow >= 0; --pow) {
            if(times[t].size() && times[t][pow] > 0) {
                times[t][pow]--;
                total--;
            }
        }
        ans.push_back(total);
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(3));
    vector<vector<int>> B(m, vector<int>(2));
    for(int i = 0; i < n; ++i) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    for(int i = 0; i < m; ++i) {
        cin >> B[i][0] >> B[i][1];
    }
    Solution s;
    vector<ll> ans = s.solve(A, B);
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}

19 43 22
26 27 10
56 65 41
20 28 15
55 74 2
65 84 51
34 37 81
40 82 98
72 84 23
38 59 67


65 30
64 93
39 71
15 37
5 64
68 59
68 93
59 70
4 88
47 7
92 17
33 47
11 51
41 45
30 82
46 93
48 92
58 36
53 81
93 9
93 40
96 95
79 83
85 72
33 22
57 38
79 35
79 60
48 28
51 3
35 77
97 41
14 40
39 18
31 34
16 17
80 56
27 85
44 57
83 53
70 14
4  13
54 11
22 66
46 68
24 47
27 68
8  17
100 81
9 32



// ------------------------------------------

35 87 58
51 59 4
62 81 95
22 84 84
18 95 70
20 70 88
16 80 24
61 90 32
49 87 70
46 62 76
  5  18
  97 55
  65 65
  78 52
  97 43
  61 14
  73 51
  78 84
  13 91
  44 97
  80 86
  33 69
  77 34
  68 56
  11 41
  48 49
  42 38
  84 4
  89 51
  23 48
  85 23
  23 28
  66 9
  100 95
  69 99
  94 49
  66 8
  63 11
  14 82
  70 26
  3  60
  45 12
  51 54
  36 84
  66 3
  86 43
  32 4
  31 63
  15 78
  98 3
  65 50
  97 43
  20 54
  88 5
  45 31
  10 24
  30 1
  34 64
  56 30
  12 66




//  -------------------------------------------
  21   52  41
  40   59  14
  74   76  56
  72   96  53
  15   82  11
  16   82  42
  2 45 26
  39   51  65
  28   37  97
  63   69  19
  46   94
  8  6
  86   97
  69   16
  75   92
  83   23
  100  84
  91   48
  49   54
  2  99
  19   45
  31   38
  36   97
  34   68
  78   92
  74   19
  52   35
  84   41
  37   32
  24   17
  35   55
  32   10
  47   94
  15   24
  76   89
  95   71
  77   85
  26   84
  67   3
  97   48
  97   88
  95   72
  70   9
  16   83
  12   36
  85   74
  90   1
  47   37
  29   66
  26   80
  95   63
  13   85
  76   23
  39   65
  16   31
  75   73
  4  35
  31   2
  63   86
  13   98