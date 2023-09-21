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

#define ar array

const int mxN=1e5;
int n, m, vis[mxN];
vector<int> adj[mxN];

void dfs(int u=0, int c=1) {
	vis[u]=c;
	for(int v: adj[u]) {
		if(vis[v]==c) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
		if(!vis[v])
			dfs(v, 3-c);
	}
}

void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i);
	}
	for(int i=0; i<n; ++i)
		cout << vis[i] << " ";
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
