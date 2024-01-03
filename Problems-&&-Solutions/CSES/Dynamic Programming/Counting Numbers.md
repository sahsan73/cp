# Counting Numbers
Problem Statement: [CSES - Counting Numbers](https://cses.fi/problemset/task/2220)   

This is a standard **_Digit DP_** problem!

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=20;
ll a, b, dp[mxN][11][2][2];


ll dfs(string &s, int i, int prev_digit, bool leading_zero, bool last_digit) {
    if(i==s.size())
        return 1;
    if(~dp[i][prev_digit+1][leading_zero][last_digit])
        return dp[i][prev_digit+1][leading_zero][last_digit];
    
    int mx=last_digit?s[i]-'0':9;
    ll res=0;
    for(int j=0; j<=mx; ++j) {
        if(j^prev_digit||leading_zero)
            res+=dfs(s, i+1, j, (leading_zero&&j==0), (last_digit&&j==mx));
    }
    return dp[i][prev_digit+1][leading_zero][last_digit] = res;
}

int main() {
    cin >> a >> b, --a;
    string s1=to_string(a), s2=to_string(b);
    memset(dp, -1, sizeof(dp));
    ll rc=dfs(s2, 0, -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll lc=dfs(s1, 0, -1, 1, 1);
    cout << (rc-lc);
    
    return 0;
}
```
