# Codeforces - Magic Numbers
Click [here](https://codeforces.com/problemset/problem/628/D) to see the problem statement.   

Standard Digit DP problem...!

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e3, mxM=2e3, M=1e9+7;
int m, d;
string a, b;
ll dp[mxN][mxM][2];

ll dfs(string &s, int i, int rx, bool ldb) {
    if(i==s.size())
        return rx==0;
    if(~dp[i][rx][ldb])
        return dp[i][rx][ldb];
    
    int mx=ldb?s[i]-'0':9;
    ll res=0;
    for(int j=0; j<=mx; ++j) {
        if(((i&1)&&j==d)||((i%2==0)&&j^d))
            res=(res+dfs(s, i+1, (rx*10+j)%m, ldb&&(j==mx)))%M;
    }
    return dp[i][rx][ldb]=res;
}

int main() {
    cin >> m >> d >> a >> b;

    /* In digit DP problems, f(a, b) ==> f(0, b) - f(0, a-1)
     *                    or             f(0, b) - f(0, a) + g(a)
     *
     * where, g(a) equals to 1 if "a" is a magic number!
     */
    memset(dp, -1, sizeof(dp));
    int rc=dfs(b, 0, 0, 1);
    memset(dp, -1, sizeof(dp));
    int lc=dfs(a, 0, 0, 1);
    // check if "a" is a magic number
    int res=1, rx=0;
    for(int i=0; i<a.size(); ++i) {
        int j=a[i]-'0';
        if(((i&1)&&j^d)||((i%2==0)&&j==d)) {
            res=0;
            break;
        }
        rx=(rx*10+j)%m;
    }
    res=res&&(rx==0);
    //cout << "rc: " << rc << ", lc: " << lc << ", res: " << res << "\n";
    cout << (rc-lc+res+M)%M;
    
    return 0;
}
```
