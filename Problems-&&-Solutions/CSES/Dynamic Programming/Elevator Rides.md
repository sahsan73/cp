# Elevator Rides
Click [here](https://cses.fi/problemset/task/1653) to see the problem statement.   

Bitmask Dynamic Programming   
Resources:
* [USACO](https://usaco.guide/problems/cses-1653-elevator-rides/solution)

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=20;
int n, x, w[mxN];
ar<int, 2> dp[1<<mxN];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> w[i];
    
    // dp[k]={a, b}
    // k --> set of people represented by bits representation of k
    // a --> min. no. of rides required for set of people (k)
    // b --> total weigth on ath (i.e., last ride) elevator ride out of total a rides
    memset(dp, 0x3f, sizeof(dp));
    dp[0]={1, 0};
    
    // k --> mask === set of people
    for(int k=1; k<(1<<n); ++k) {
        for(int i=0; i<n; ++i) {
            if(k&1<<i) {
                int k2 = k^(1<<i); // prev set of people
                int cnt=dp[k2][0]; // total cnt for k2 set of people
                int wt=dp[k2][1]; // last ride weight of prev 'cnt' rides
                
                if(wt+w[i]<=x)
                    wt+=w[i];
                else
                    ++cnt, wt=w[i];
                
                dp[k]=min(dp[k], {cnt, wt});
            }
        }
    }
    cout << dp[(1<<n)-1][0];
    
    return 0;
}
```
