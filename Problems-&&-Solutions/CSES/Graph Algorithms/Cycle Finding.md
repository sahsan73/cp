# Cycle Finding
Click [here](https://cses.fi/problemset/task/1197) to see the problem statement.   

## APPROACH: Bellman Ford Algorithm
![explanation image](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/graph-algorithms-cycle-finding.png)   

Sample test case to support case #2
```
4 4
1 2 -4
2 3 1
3 1 1
3 4 7
```

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2.5e3;
int n, m, p[mxN], vis[mxN];
vector<ar<int, 3>> e;
ll d[mxN];

int main() {
    cin >> n >> m;
    for(int i=0, a, b, c; i<m; ++i) {
        cin >> a >> b >> c, --a, --b;
        e.push_back({c, a, b});
    }
    
    memset(d, 0x3f, sizeof(d));
    iota(p, p+n, 0);
    d[0]=0;
    int x;
    for(int i=0; i<n; ++i) {
        x=-1;
        for(int j=0; j<m; ++j) {
            if(d[e[j][1]]+e[j][0]<d[e[j][2]]) {
                d[e[j][2]]=d[e[j][1]]+e[j][0];
                p[e[j][2]]=e[j][1];
                x=e[j][2];
            }
        }
    }
    
    if(~x) {
        // case #2
        while(!vis[x]) {
            vis[x]=1;
            x=p[x];
        }
        
        vector<int> cyc;
        while(cyc.empty()||x^cyc[0]) {
            cyc.push_back(x);
            x=p[x];
        }
        cyc.push_back(x);
        reverse(cyc.begin(), cyc.end());
        cout << "YES\n";
        for(int y: cyc)
            cout << y+1 << " ";
    } else
        cout << "NO";
    
    return 0;
}
```
