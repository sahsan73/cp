/*
Problem Statement: https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/gcd-on-directed-graph-1122228a/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORITHM
    - Simple DFS to calculate overall minimum GCD
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, who[mxN], c[mxN], c2[mxN], ans;
vector<int> adj[mxN], adj2[mxN], adj3[mxN], st;
bool vis[mxN];
unordered_set<int> dp[mxN];

void dfs1(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs1(v);
	}
	st.push_back(u);
}

void dfs2(int u, int rp) {
	vis[u]=0;
	who[u]=rp;
	for(int v: adj2[u]) {
		if(vis[v])
			dfs2(v, rp);
	}
	c2[rp]=__gcd(c2[rp], c[u]);
}

void dfs3(int u) {
	vis[u]=1;
	dp[u].insert(c2[u]);
	ans=min(ans, c2[u]);
	for(int v: adj3[u]) {
		if(!vis[v])
			dfs3(v);
		for(auto &it: dp[v]) {
			int x=__gcd(it, c2[u]);
			dp[u].insert(x);
			ans=min(ans, x);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs1(i);
	}
	for(int i=n-1; ~i; --i) {
		if(vis[st[i]])
			dfs2(st[i], st[i]);
	}

	for(int i=0; i<n; ++i) {
		for(int j: adj[i]) {
			if(who[i]==who[j])
				continue;
			adj3[who[i]].push_back(who[j]);
		}
	}
	ans=1e9;
	for(int i=0; i<n; ++i) {
		if(!vis[i]&&who[i]==i)
			dfs3(i);
	}
	cout << ans;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORITHM
    - Toposort on condensed graph to calculate minimum GCD
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, who[mxN], c[mxN], c2[mxN], ans;
vector<int> adj[mxN], adj2[mxN], adj3[mxN], st, st2;
bool vis[mxN];
unordered_set<int> dp[mxN];

void dfs1(int u, vector<int> adj[mxN], vector<int> &st) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs1(v, adj, st);
	}
	st.push_back(u);
}

void dfs2(int u, int rp) {
	vis[u]=0;
	who[u]=rp;
	for(int v: adj2[u]) {
		if(vis[v])
			dfs2(v, rp);
	}
	c2[rp]=__gcd(c2[rp], c[u]);
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs1(i, adj, st);
	}
	for(int i=n-1; ~i; --i) {
		if(vis[st[i]])
			dfs2(st[i], st[i]);
	}

	for(int i=0; i<n; ++i) {
		for(int j: adj[i]) {
			if(who[i]==who[j])
				continue;
			adj3[who[i]].push_back(who[j]);
		}
	}
	for(int i=0; i<n; ++i) {
		if(!vis[i]&&who[i]==i)
			dfs1(i, adj3, st2);
	}
	ans=1e9;
	for(int u: st2) {
		dp[u].insert(c2[u]);
		ans=min(ans, c2[u]);
		for(int v: adj3[u]) {
			for(auto &it: dp[v]) {
				int x=__gcd(c2[u], it);
				dp[u].insert(x);
				ans=min(ans, x);
			}
		}
	}
	cout << ans;

	return 0;
}
