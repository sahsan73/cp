/*
Problem Statement: https://cses.fi/problemset/task/1666/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, who[mxN], vis[mxN];
vector<int> adj[mxN];

void dfs(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs(v);
	}
}

void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> res; // component representative
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i), res.push_back(i+1);
	}
	cout << res.size()-1 << "\n";
	for(int i=1; i<res.size(); ++i)
		cout << res[i-1] << " " << res[i] << "\n";
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
