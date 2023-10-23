/*
Problem Statement: https://cses.fi/problemset/task/1669/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, vis[mxN], vis2[mxN], p[mxN];
vector<int> adj[mxN];

void dfs(int u) {
	vis[u]=vis2[u]=1;
	for(int v: adj[u]) {
		if(!vis[v]) {
			p[v]=u;
			dfs(v);
		} else if(vis2[v]) {
			int s=v, t=u;
			vector<int> c;
			c.push_back(s);
			for(; t^s; t=p[t])
				c.push_back(t);
			c.push_back(s);
			reverse(c.begin(), c.end());
			cout << c.size() << "\n";
			for(int i=0; i<c.size(); ++i)
				cout << c[i]+1 << " ";
			exit(0);
		}
	}
	vis2[u]=0;
}

void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i);
	}
	cout << "IMPOSSIBLE";
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
