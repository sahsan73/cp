# Make The Fence Great Again
Problem Statement: <https://codeforces.com/problemset/problem/1221/D>   

Can we approach with greedy...🤔?   
![Greedy thought explanation](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/Codeforces/assets/images/1221D-make-the-fence-great-again-greedy-thought.png)   

Does this problem exhibit the characteristic(s) of dynamic programming...🤔?   
![Overlapping subproblems example](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/Codeforces/assets/images/1221D-make-the-fence-great-again-overlapping-subproblems.png)   

*Claim:* To make the adjacent boards **unequal**, maximum increase any board can have is 2.   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e5;
int n, q, a[mxN], b[mxN];
ll dp[mxN][3];

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i] >> b[i];
    
    // memset(dp, 0x3f, sizeof(dp)); // causes TLE
    memset(dp, 0x3f, n*3*8);
    dp[0][0]=0, dp[0][1]=b[0], dp[0][2]=2*b[0];
    for(int i=1; i<n; ++i)
        for(int j=0; j<=2; ++j)
            for(int k=0; k<=2; ++k)
                if(a[i]+j!=a[i-1]+k)
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+j*b[i]);

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> q;
    while(q--)
        solve();
    return 0;
}
```
