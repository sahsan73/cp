# CPCRC1C - Sum of Digits
Problem Statement: Click [here](https://www.spoj.com/problems/CPCRC1C/) to view the statement.   

This is a standard **_Digit DP_** problem!

### Implementation:
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=10, mxS=90;
int a, b;
ll dp[mxN][mxS][2];

// last_digit --> last digit of last branch in recursion tree which keeps
// our generating integer less than the orginal/target number
ll dfs(string &s, int i, int sum, bool last_digit) {
    if(i==s.size())
        return sum;
    if(~dp[i][sum][last_digit])
        return dp[i][sum][last_digit];
    
    int mx=last_digit?s[i]-'0':9;
    ll res=0;
    for(int j=0; j<=mx; ++j)
        res+=dfs(s, i+1, sum+j, last_digit&&(j==mx));
    return dp[i][sum][last_digit] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin>>a>>b && (~a||~b)) {
        if(a)
            --a;
        string s1=to_string(a), s2=to_string(b);
        // cout << (dfs(s2, 0, 0, 1) - dfs(s1, 0, 0, 1)) << "\n";
        memset(dp, -1, sizeof(dp));
        ll r=dfs(s2, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        ll l=dfs(s1, 0, 0, 1);
        cout << (r-l) << "\n";
    }
    
    return 0;
}
```
