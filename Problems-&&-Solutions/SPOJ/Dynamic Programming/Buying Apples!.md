# SPOJ - Buying Apples!
Click [here](https://www.spoj.com/problems/ABA12C/) to see the problem statement.   

Approach: 0/N Knapsack   

### Implementation: Bottom - Up (Iteration + Tabulation)
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxK=100;
int n, k, p[mxK+1], dp[mxK+1], w[mxK+1], v[mxK+1];

void solve() {
    cin >> n >> k;
    for(int i=1; i<=k; ++i)
        cin >> p[i];
    int cnt=1;
    for(int i=1; i<=k; ++i)
        if(~p[i])
            w[cnt]=i, v[cnt]=p[i], ++cnt;
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for(int i=1; i<=k; ++i) {
        for(int j=1; j<cnt; ++j)
            if(w[j]<=i)
                dp[i]=min(dp[i], v[j]+dp[i-w[j]]);
    }
    if(dp[k]>=1e9)
        cout << "-1\n";
    else
        cout << dp[k] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
```
