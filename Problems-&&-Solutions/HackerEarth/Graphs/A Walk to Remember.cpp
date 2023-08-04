/*
Problem Statement: https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORITHM
    - Find SCCs
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, cnt;
vector<int> adj[mxN], adj2[mxN], st;
bool vis[mxN], ans[mxN];

void dfs1(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs1(v);
	}
	st.push_back(u);
}

void dfs2(int u) {
	vis[u]=0;
	ans[u]=1;
	for(int v: adj2[u]) {
		if(vis[v])
			dfs2(v);
	}
	++cnt;
}

int main() {
	cin >> n >> m;
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
		if(vis[st[i]]) {
			dfs2(st[i]);
			if(cnt==1)
				ans[st[i]]=0;
			cnt=0;
		}
	}
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
