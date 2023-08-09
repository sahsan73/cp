/*
Problem Statement: https://cses.fi/problemset/task/1683
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORIGHT FOR SCCs
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, who[mxN];
vector<int> adj[mxN], adj2[mxN];
bool vis[mxN], vis2[mxN];
stack<int> st;

void dfs1(int u) {
	vis[u]=1;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs1(v);
	}
	st.push(u);
}

void dfs2(int u, int rp) {
	who[u]=rp;
	vis2[u]=1;
	for(int v: adj2[u]) {
		if(!vis2[v])
			dfs2(v, rp);
	}
}

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj2[b].push_back(a); // reverse adjacency list
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs1(i);
	}
	int k=0;
	while(!st.empty()) {
		int u=st.top(); st.pop();
		if(!vis2[u])
			dfs2(u, ++k);
	}
	cout << k << "\n";
	for(int i=0; i<n; ++i)
		cout << who[i] << " ";

	return 0;
}
