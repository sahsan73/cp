# LightOJ - Investigation
Click [here](https://lightoj.com/problem/investigation) to see the problem statement.   

Approach: Digit DP   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=10, mxS=90, mxK=1e4;
int a, b, k, dp[mxN][mxS][mxK][2];

// ldb --> last digit bound which makes sure that our
// generating/constructing number (x) <= original number (s)
// rx --> reminder when x % k
// sd --> sum of digits
int dfs(string &s, int i, int rx, int sd, bool ldb) {
    if(i==s.size())
        return rx==0&&rsd%k==0;
    if(~dp[i][rx][rsd][ldb])
        return dp[i][rx][rsd][ldb];
    
    int mx=ldb?s[i]-'0':9;
    int cnt=0;
    for(int j=0; j<=mx; ++j)
        cnt+=dfs(s, i+1, (rx*10+j)%k, (sd+j), ldb&&(j==mx));
    return dp[i][rx][rsd][ldb]=cnt;
}

void solve() {
    cin >> a >> b >> k, --a;
    string s1=to_string(a), s2=to_string(b);
    memset(dp, -1, sizeof(dp));
    int rc=dfs(s2, 0, 0, 0, 1);
    memset(dp, -1, sizeof(dp));
    int lc=dfs(s1, 0, 0, 0, 1);
    cout << (rc-lc) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t=1, i=1;
    cin >> t;
    while(t--) {
    	cout << "Case " << i++ << ": ";
    	solve();
    }
    return 0;
}
```

VERDICT: MEMORY LIMIT EXCEEDED (MLE), this is expected!   
Optimization: If you noticed, the sum of digits (sd) can only go upto 90. So if we have $k$ LARGER THAN $mxS$, then there is no number exist
which satisfy both the conditions given in the problem statment as because $sd$ will NEVER be divisible by $k$ in that case!   
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=10, mxS=90, mxK=1e4;
int a, b, k, dp[mxN][mxS][mxS][2];

// ldb --> last digit bound which makes sure that our
// generating/constructing number (x) <= original number (s)
// rx --> reminder when x % k
// rsd --> reminder (sum of digits) % k
int dfs(string &s, int i, int rx, int rsd, bool ldb) {
    if(i==s.size())
        return rx==0&&rsd%k==0;
    if(~dp[i][rx][rsd][ldb])
        return dp[i][rx][rsd][ldb];
    
    int mx=ldb?s[i]-'0':9;
    int cnt=0;
    for(int j=0; j<=mx; ++j)
        cnt+=dfs(s, i+1, (rx*10+j)%k, (rsd+j), ldb&&(j==mx));
    return dp[i][rx][rsd][ldb]=cnt;
}

void solve() {
    cin >> a >> b >> k, --a;
    if(k>mxS) {
        cout << "0\n";
        return;
    }
    string s1=to_string(a), s2=to_string(b);
    memset(dp, -1, sizeof(dp));
    int rc=dfs(s2, 0, 0, 0, 1);
    memset(dp, -1, sizeof(dp));
    int lc=dfs(s1, 0, 0, 0, 1);
    cout << (rc-lc) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t=1, i=1;
    cin >> t;
    while(t--) {
    	cout << "Case " << i++ << ": ";
    	solve();
    }
    return 0;
}
```
