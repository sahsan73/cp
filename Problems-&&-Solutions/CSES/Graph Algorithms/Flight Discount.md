# Flight Discount
Click [here](https://cses.fi/problemset/task/1195) to see the problem description.   

### APPROACH: DIJKSTRA ALGORITHM + DP
![explanation-image](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/graph-algorithms-flight-discount.png)   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m;
ll d1[mxN], d2[mxN];
vector<ar<int, 2>> adj[mxN], adj2[mxN];

void solve(vector<ar<int, 2>> adj[mxN], int s, ll d[mxN]) {
    memset(d, 0x3f, sizeof(d1));
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({0, s});
    d[s]=0;
    
    while(!pq.empty()) {
        ar<ll, 2> u=pq.top();
        pq.pop();
        if(u[0]>d[u[1]])
            continue;
        for(ar<int, 2> v: adj[u[1]]) {
            if(u[0]+v[0]<d[v[1]]) {
                d[v[1]]=u[0]+v[0];
                pq.push({d[v[1]], v[1]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0, a, b, c; i<m; ++i) {
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
        adj2[b].push_back({c, a});
    }
    
    solve(adj, 0, d1);
    solve(adj2, n-1, d2);
    
    ll ans=1e18;
    for(int i=0; i<n; ++i) {
        for(ar<int, 2> j: adj[i])
            ans=min(ans, d1[i]+j[0]/2+d2[j[1]]);
    }
    cout << ans;
    
    return 0;
}
```

&nbsp;

### APPROACH: GREEDY THOUGHT
Take out the path with minimum price and apply discount on maximum flight price. But, what if there are multiple 
paths with minimum price. Then you have to check in every path <-- *_BAD STRATEGY_*
