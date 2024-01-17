# F - LCS
Click [here](https://atcoder.jp/contests/dp/tasks/dp_f) to see the problem statement.   


#### Implementation: Top - Down (Recursion + Memoization)
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=3e3;
int n, m, dp[mxN][mxN];
string s, t, a;

int dfs(int i=n-1, int j=m-1) {
    if(i<0||j<0)
        return 0;
    if(~dp[i][j])
        return dp[i][j];
    
    if(s[i]==t[j])
        return dp[i][j]=1+dfs(i-1, j-1);
    return dp[i][j]=max(dfs(i, j-1), dfs(i-1, j));
}

void dfs2(int i=n-1, int j=m-1) {
    if(i<0||j<0)
        return;
    
    if(s[i]==t[j])
        a+=s[i], dfs2(i-1, j-1);
    else if(dfs(i, j)==dfs(i-1, j))
        dfs2(i-1, j);
    else
        dfs2(i, j-1);
}

int main() {
    cin >> s >> t;
    n=s.size(), m=t.size();
    
    memset(dp, -1, sizeof(dp));
    dfs();
    dfs2();
    reverse(a.begin(), a.end());
    cout << a;
    
    return 0;
}
```

#### Implementation: Bottom - Up (Iteration + Tabulation)
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=3e3;
int n, m, dp[mxN+1][mxN+1];
char s[mxN+2], t[mxN+2];

int main() {
    scanf("%s\n%s", s+1, t+1);
    n=strlen(s+1), m=strlen(t+1);
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i]==t[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    //cout << dp[n][m] << "\n";
    
    string a;
    int i=n, j=m;
    while(dp[i][j]) {
        if(s[i]==t[j])
            a+=s[i], --i, --j;
        else if(dp[i][j]==dp[i][j-1])
            --j;
        else
            --i;
    }
    reverse(a.begin(), a.end());
    cout << a;
    
    return 0;
}
```
