# G - Longest Path
Click [here](https://atcoder.jp/contests/dp/tasks/dp_g) to see the problem statement.   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e5;
int n, m, vis[mxN], dp[mxN], ans;
vector<int> adj[mxN];

void dfs(int u) {
    vis[u]=1;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs(v);
        dp[u]=max(dp[u], 1+dp[v]);
        ans=max(ans, dp[u]);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0, x, y; i<m; ++i) {
        cin >> x >> y, --x, --y;
        adj[x].push_back(y);
    }
    
    for(int i=0; i<n; ++i)
        if(!vis[i])
            dfs(i);
    cout << ans;
    
    return 0;
}
```
