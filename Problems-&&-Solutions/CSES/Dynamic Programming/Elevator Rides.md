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
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0]={1, 0};
    // k <-- mask
    for(int k=1; k<(1<<n); ++k) {
        for(int i=0; i<n; ++i) {
            if(k&1<<i) {
                int k2=k^(1<<i); // previous set of people
                int cnt=dp[k2][0]; // min no. of rides for set of people represented by k2
                /*
                 * 'cnt' rides required for set of people represented by k2
                 * and in those 'cnt' rides, wt is total weight of last ride (out of
                 * 'cnt' rides)
                */ 
                int wt=dp[k2][1];
                
                if(wt+w[i]<=x)
                    wt+=w[i];
                else {
                    ++cnt;
                    wt=w[i];
                }
                dp[k]=min(dp[k], {cnt, wt});
            }
        }
    }
    cout << dp[(1<<n)-1][0];
    
    return 0;
}
```
