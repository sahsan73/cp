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

const int mxN=1e5;
int n, m, who[mxN];
ll k[mxN], k2[mxN], dp[mxN];
vector<int> adj[mxN], adj2[mxN], adj3[mxN], st;
bool vis[mxN];

// topo sort
void dfs1(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs1(v);
	}
	st.push_back(u);
}

// kosaraju's scc
void dfs2(int u, int rp) {
	vis[u]=0;
	who[u]=rp;
	for(int v: adj2[u]) {
		if(vis[v])
			dfs2(v, rp);
	}
	k2[rp]+=k[u];
}

void dfs3(int u) {
	vis[u]=1;
	for(int v: adj3[u]) {
		if(!vis[v])
			dfs3(v);
		dp[u]=max(dp[u], dp[v]);
	}
	dp[u]+=k2[u];
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> k[i];
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	
	// for topo sort
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs1(i);
	}
	// kosaraju's scc
	for(int i=n-1; ~i; --i) {
		if(vis[st[i]])
			dfs2(st[i], st[i]);
	}
	
	// create condensed graph
	for(int i=0; i<n; ++i) {
		for(int j: adj[i]) {
			if(who[i]==who[j])
				continue;
			adj3[who[i]].push_back(who[j]);
		}
	}
	ll ans=0;
	for(int i=0; i<n; ++i) {
		if(!vis[i]&&who[i]==i) {
			dfs3(i);
			ans=max(ans, dp[i]);
		}
	}
	cout << ans;

	return 0;
}
