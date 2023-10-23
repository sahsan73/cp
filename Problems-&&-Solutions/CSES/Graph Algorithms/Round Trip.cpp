/*
Problem Statement: https://cses.fi/problemset/result/7470847/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, vis[mxN], p[mxN];
vector<int> adj[mxN];

void dfs(int u, int pr=-1) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v]) {
			p[v]=u;
			dfs(v, u);
		} else if(v^pr) {
			int s=v, t=u;
			vector<int> c;
			c.push_back(s);
			for(; t^s; t=p[t])
				c.push_back(t);
			c.push_back(s);
			cout << c.size() << "\n";
			for(int i=0; i<c.size(); ++i)
				cout << c[i]+1 << " ";
			exit(0);
		}
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
