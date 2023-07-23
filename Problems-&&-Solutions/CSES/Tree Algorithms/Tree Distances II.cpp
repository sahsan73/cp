#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, d[mxN];
ll s[mxN], ans[mxN];
vector<int> adj[mxN];

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

void dfs2(int u, ll sd, int p=-1) {
	ans[u]=sd;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs2(v, sd-s[v]+(n-s[v]), u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

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
	dfs2(0, sd);
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
