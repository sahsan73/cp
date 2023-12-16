# Counting Towers
Problem Statement: <https://cses.fi/problemset/task/2413>   

Diagram Illustration:   
![Diagram illustrations](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/counting-towers-diagram-illustrations.png)   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6, M=1e9+7;
int t, n;
ll dp[mxN+1][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[1][1] = dp[1][2] = 1;
    for(int i=2; i<=mxN; ++i) {
        dp[i][1] = (dp[i-1][2]+4*dp[i-1][1])%M;
        dp[i][2] = (2*dp[i-1][2]+dp[i-1][1])%M;
    }
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (dp[n][1]+dp[n][2])%M << "\n";
    }
    
    return 0;
}
```
