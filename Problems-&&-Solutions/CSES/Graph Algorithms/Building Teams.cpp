/*
Problem Statement: https://cses.fi/problemset/task/1668/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BIPARTITE GRAPH
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5;
int n, m, vis[mxN];
vector<int> adj[mxN];

bool dfs(int u, int p=-1, int c=1) {
	vis[u]=c;
	for(int v: adj[u]) {
		if(!vis[v]) {
			if(!dfs(v, u, 3-c))
				return 0;
		} else if(v!=p&&vis[v]==c)
			return 0;
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i]&&!dfs(i)) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for(int i=0; i<n; ++i)
		cout << vis[i] << " ";

	return 0;
}
