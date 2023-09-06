#include <bits/stdc++.h>
using namespace std;

#define ar array
int n, m, vis[10];
vector<ar<int, 2>> adj[10];

int dfs(int u) {
	vis[u]=1;
	int r=0;
	for(ar<int, 2> v: adj[u]) {
		if(vis[v[0]])
			continue;
		r=max(r, v[1]+dfs(v[0]));
	}
	vis[u]=0;
	return r;
}

int main() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	int a=0;
	for(int i=0; i<n; ++i) {
		memset(vis, 0, sizeof(vis));
		a=max(a, dfs(i));
	}
	cout << a;

	return 0;
}
