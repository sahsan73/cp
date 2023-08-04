/*
Problem Statement: https://cses.fi/problemset/task/1682
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, who[mxN], cnt;
vector<int> adj[mxN], adj2[mxN];
bool vis[mxN];
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
	vis[u]=0;
	who[u]=rp;
	for(int v: adj2[u]) {
		if(vis[v])
			dfs2(v, rp);
	}
	++cnt;
}

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs1(i);
	}

	vector<int> rps; // representatives of SCCs
	while(!st.empty()) {
		int u=st.top();
		st.pop();
		if(vis[u]) {
			dfs2(u, u);
			if(cnt==n) {
				cout << "YES";
				return 0;
			} else {
				rps.push_back(u);
			}
			cnt=0;
		}
	}
	cout << "NO\n" << rps[1]+1 << " " << rps[0]+1;

	return 0;
}
