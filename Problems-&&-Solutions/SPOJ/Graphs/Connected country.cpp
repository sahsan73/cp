/*
Problem Statement: https://www.spoj.com/problems/CONGRAPH/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=8e5;
int n, m, vis[mxN];
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
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cnt=0;
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i), ++cnt;
	}
	cout << (cnt-1);

	return 0;
}
