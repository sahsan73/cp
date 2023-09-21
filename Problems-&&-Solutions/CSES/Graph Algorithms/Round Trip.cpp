/*
Problem Statement: https://cses.fi/problemset/task/1669/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, vis[mxN], p[mxN], x, y;
vector<int> adj[mxN];

void dfs(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v]) {
			p[v]=u;
			dfs(v);
		} else if(v!=p[u]) {
			x=u, y=v;
			return;
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

	memset(p, -1, sizeof(p));
	x=y=-1;
	for(int i=0; i<n; ++i) {
		if(!vis[i]&&x==-1)
			dfs(i);
	}
	if(x==-1) {
		cout << "IMPOSSIBLE";
	} else {
		vector<int> res;
		res.push_back(x);
		for(int i=y; i^x; i=p[i])
			res.push_back(i);
		res.push_back(x);
		reverse(res.begin(), res.end());
		cout << res.size() << "\n";
		for(int i: res)
			cout << i+1 << " ";
	}
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
