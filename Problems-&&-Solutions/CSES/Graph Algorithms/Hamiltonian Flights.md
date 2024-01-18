# Hamiltonian Flights
Click [here](https://cses.fi/problemset/task/1690) to see the problem statement.   

APPROACH: dfs + bitmask dp   

Resources
* [HackerEarth](https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/)

#### Implementation: Top - Down
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=20, M=1e9+7;
int n, m, dp[mxN][1<<mxN];
vector<int> adj[mxN];

int dfs(int u=0, int vis=1) {
    if((1<<n)-1==vis)
        return u==n-1;
    // pruning --> destination vertex is visited but not
    // all the other vertices are visited
    if(vis&(1<<(n-1)))
        return 0;
    if(~dp[u][vis])
        return dp[u][vis];
    
    int res=0;
    for(int v: adj[u])
        if(!(vis&(1<<v)))
            res=(res+dfs(v, vis|1<<v))%M;
    return dp[u][vis]=res;
}

int main() {
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs();
    
    return 0;
}
```
