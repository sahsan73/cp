/*
Problem Statement: https://cses.fi/problemset/task/1686
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORITHM + DYNAMIC PROGRAMMING
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, k[mxN], who[mxN], vis[mxN];
vector<int> adj[mxN], adj2[mxN], st, adj3[mxN];
ll k2[mxN], dp[mxN];

// toposort
void dfs(int u) {
	vis[u]=1;
	for(int v: adj[u])
		if(!vis[v])
			dfs(v);
	st.push_back(u);
}

// kosaraju's algorithm
void dfs2(int u, int rp) {
	vis[u]=0;
	k2[rp]+=k[u];
	who[u]=rp;
	for(int v: adj2[u])
		if(vis[v])
			dfs2(v, rp);
}

// dp to calculate max coins
void dfs3(int u) {
	vis[u]=1;
	for(int v: adj3[u]) {
		if(!vis[v])
			dfs3(v);
		dp[u]=max(dp[u], dp[v]);
	}
	dp[u]+=k2[u];
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> k[i];
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}

	// toposort
	for(int i=0; i<n; ++i)
		if(!vis[i])
			dfs(i);
	// kosaraju's algorithm
	for(int i=n-1; ~i; --i)
		if(vis[st[i]])
			dfs2(st[i], st[i]);

	// condensed adjacency matrix
	for(int i=0; i<n; ++i) {
		for(int j: adj[i]) {
			if(who[i]==who[j])
				continue;
			adj3[who[i]].push_back(who[j]);
		}
	}
	// apply dp in order to calculate max coins
	ll ans=0;
	for(int i=0; i<n; ++i)
		if(!vis[i]&&who[i]==i)
			dfs3(i), ans=max(ans, dp[i]);
	cout << ans;
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
