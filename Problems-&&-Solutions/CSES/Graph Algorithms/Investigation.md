# Investigation
Click [here]() to see the problem statement.   

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, M=1e9+7;
int n, m;
vector<ar<int, 2>> adj[mxN];
// d[i][0]-->min price, d[i][1]-->cnt min price routes
// d[i][2]-->min number of vertices in a min price route
// d[i][3]-->max number of vertices in a min price route
ar<ll, 4> d[mxN];

void solve() {
    cin >> n >> m;
    for(int i=0, a, b, c; i<m; ++i) {
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
    }
    
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({0, 0});
    memset(d, 0x3f, sizeof(d));
    d[0][0]=d[0][2]=0, d[0][1]=1;
    for(int i=0; i<n; ++i)
        d[i][3]=0;
    while(pq.size()) {
        ar<ll, 2> u=pq.top();
        pq.pop();
        if(u[0]>d[u[1]][0])
            continue;
        for(ar<int, 2> v: adj[u[1]]) {
            if(u[0]+v[0]<d[v[1]][0]) {
                d[v[1]][0]=u[0]+v[0];
                d[v[1]][1]=d[u[1]][1];
                d[v[1]][2]=d[u[1]][2]+1;
                d[v[1]][3]=d[u[1]][3]+1;
                pq.push({d[v[1]][0], v[1]});
            }
            else if(u[0]+v[0]==d[v[1]][0]) {
                d[v[1]][1]=(d[v[1]][1]+d[u[1]][1])%M;
                d[v[1]][2]=min(d[v[1]][2], d[u[1]][2]+1);
                d[v[1]][3]=max(d[v[1]][3], d[u[1]][3]+1);
            }
        }
    }
    for(int i=0; i<4; ++i)
    cout << d[n-1][i] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
```
