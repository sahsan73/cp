/*
Problem Statement: https://cses.fi/problemset/task/1688
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* APPROACH: DFS */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, p[mxN], d[mxN], anc[mxN][20];
vector<int> adj[mxN];

void dfs(int u=0) {
	anc[u][0]=p[u];
	for(int j=1; j<20; ++j)
		anc[u][j]=~anc[u][j-1]?anc[anc[u][j-1]][j-1]:-1;
	for(int v: adj[u]) {
		if(v==p[u])
			continue;
		d[v]=d[u]+1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if(d[u]<d[v])
		swap(u, v);
	int diff=d[u]-d[v];
	for(int j=19; ~j; --j)
		if(diff&1<<j)
			u=anc[u][j];
	if(u==v)
		return u;
	for(int j=19; ~j; --j) {
		if(anc[u][j]^anc[v][j]) {
			u=anc[u][j];
			v=anc[v][j];
		}
	}
	return anc[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	memset(anc[0], -1, sizeof(anc[0]));
	for(int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs();
	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		cout << lca(a, b)+1 << "\n";
	}

	return 0;
}
