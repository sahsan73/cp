/*
Problem Statement: https://cses.fi/problemset/task/1666/
*/
#include <bits/stdc++.h>
using namespace std;

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

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> co;
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i), co.push_back(i+1);
	}
	cout << co.size()-1 << "\n";
	for(int i=1; i<co.size(); ++i)
		cout << co[0] << " " << co[i] << "\n";

	return 0;
}
