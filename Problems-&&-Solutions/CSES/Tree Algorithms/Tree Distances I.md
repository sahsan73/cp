# Tree Distances I
Click [here](https://cses.fi/problemset/task/1132) to see the problem statement.   

APPROACH: RE-ROOTING + DYNAMIC PROGRAMMING

![explanation-image-1](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/tree-algorithms-tree-distances-i-part-1.png)   
![explanation-image-2](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/tree-algorithms-tree-distances-i-part-2.png)   


#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, d[mxN], ans[mxN]; // d[i] --> height of the substree(i)
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
    for(int v: adj[u]) {
        if(v==p)
            continue;
        dfs(v, u);
        d[u]=max(d[u], 1+d[v]);
    }
}

void dfs2(int u=0, int p=-1, int pd=0) {
    ans[u]=max(d[u], pd);
    vector<ar<int, 2>> w;
    w.push_back({pd, p});
    for(int v: adj[u])
        if(v^p)
            w.push_back({d[v]+1, v});
    sort(w.begin(), w.end(), greater<ar<int, 2>>());
    
    for(int v: adj[u])
        if(v^p)
            dfs2(v, u, w[0][1]==v?w[1][0]+1:w[0][0]+1);
}

int main() {
    cin >> n;
    for(int i=1, a, b; i<n; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs();
    dfs2();
    for(int i=0; i<n; ++i)
        cout << ans[i] << " ";
    
    return 0;
}
```
