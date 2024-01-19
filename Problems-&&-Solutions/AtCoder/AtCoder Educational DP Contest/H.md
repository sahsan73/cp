# H - Grid 1
Click [here](https://atcoder.jp/contests/dp/tasks/dp_h) to see the problem statement.   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e3, M=1e9+7;
int n, m, dp[mxN][mxN];
string s[mxN];


int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> s[i];
    
    dp[0][0]=1;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(s[i][j]=='#') {
                dp[i][j]=0;
                continue;
            }
            if(i>0)
                dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
            if(j>0)
                dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
        }
    }
    cout << dp[n-1][m-1];
    
    return 0;
}
```
