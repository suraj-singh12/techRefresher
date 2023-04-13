#include <bits/stdc++.h>
using namespace std;

#define ll            long long

int main() {
    int n;
    cin >> n;
    vector<int> nums (n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    int ctr1 = 0;
    int i = 0;
    while(i < n) {
        int curr = nums[i];
        i++;
        if(nums[i] > curr) {
            while(i < n && nums[i] > curr) i++;
            ctr1 += 2;
        } 
        if(i < n) {
            curr = nums[i];
            if()
        }
    }
    return 0;
}