/*
Problem Statement: https://cses.fi/problemset/task/1133/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, d[mxN], s[mxN];
vector<int> adj[mxN];
ll ans[mxN];

void dfs(int u=0, int p=-1) {
	s[u]=1;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v, u);
		s[u]+=s[v];
	}
}

void dfs2(int u, int p, ll sd) {
	//cout << "(" << u << ", " << p << ", " << s << ")\n";
	ans[u]=sd;
	for(int v: adj[u]) {
		if(v^p)
			dfs2(v, u, sd+(n-s[v])-s[v]);
	}
}

int main() {
	cin >> n;
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	ll sd=0;
	for(int i=0; i<n; ++i)
		sd+=d[i];
	dfs2(0, -1, sd);
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
