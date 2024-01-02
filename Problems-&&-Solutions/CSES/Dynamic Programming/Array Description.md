# Array Description
Problem Statement: <https://cses.fi/problemset/task/1746>   

Explanation:   
![dynamic programming characteristics](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/array-description.png)   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=1e2, M=1e9+7;
int n, m, x[mxN], dp[mxN][mxM+2];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> x[i];
    
    if(x[0]==0)
        for(int j=1; j<=m; ++j)
            dp[0][j]=1;
    else
        dp[0][x[0]] = 1;
    for(int i=1; i<n; ++i) {
        if(x[i]==0) {
            for(int j=1; j<=m; ++j)
                dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%M+dp[i-1][j+1])%M;
        } else {
            for(int j=1; j<=m; ++j)
                dp[i][j] = 0;
            dp[i][x[i]] = ((dp[i-1][x[i]-1]+dp[i-1][x[i]])%M+dp[i-1][x[i]+1])%M;
        }
    }
    
    int ans=0;
    for(int j=1; j<=m; ++j)
        ans = (ans + dp[n-1][j])%M;
    cout << ans;
    
    return 0;
}
```
