/*
Problem Statement: https://codeforces.com/problemset/problem/982/C
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, s[mxN], p[mxN];
vector<int> adj[mxN];

void dfs(int u=0, int par=-1) {
	s[u]=1;
	p[u]=par;
	for(int v: adj[u]) {
		if(v==par)
			continue;
		dfs(v, u);
		s[u]+=s[v];
	}
}

int main() {
	cin >> n;
	if(n&1) {
		cout << -1;
		return 0;
	}
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs();
	int k=0;
	for(int i=0; i<n; ++i) {
		if(p[i]!=-1&&s[i]%2==0)
			++k;
	}
	cout << k;

	return 0;
}
