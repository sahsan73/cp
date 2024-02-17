# Building Teams
Click [here](https://cses.fi/problemset/task/1668/) to see the problem description.   

BIPARTITE GRAPH    

#### Implemenation - DFS
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, vis[mxN];
vector<int> adj[mxN];

void dfs(int u, int c=1) {
    vis[u]=c;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs(v, 3-c);
        else if(vis[v]==c) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=0; i<n; ++i)
        if(!vis[i])
            dfs(i);
    for(int i=0; i<n; ++i)
        cout << vis[i] << " ";
    
    return 0;
}
```

&nbsp;

#### Implementation - BFS
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, vis[mxN];
vector<int> adj[mxN];

void bfs(int u, int c=1) {
    vis[u]=c;
    queue<int> qu;
    qu.push(u);
    while(!qu.empty()) {
        u=qu.front();
        qu.pop();
        c=vis[u];
        for(int v: adj[u]) {
            if(!vis[v]) {
                vis[v]=3-c;
                qu.push(v);
            } else if(vis[v]==c) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=0; i<n; ++i)
        if(!vis[i])
            bfs(i);
    for(int i=0; i<n; ++i)
        cout << vis[i] << " ";
    
    return 0;
}
```
