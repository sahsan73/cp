/*
Problem Statement: https://cses.fi/problemset/task/1681
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: TOPO SORT + DP
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, M=1e9+7;
int n, m, indeg[mxN], dp[mxN];
vector<int> adj[mxN], st;

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		++indeg[b];
	}

	queue<int> q;
	for(int i=0; i<n; ++i) {
		if(indeg[i]==0)
			q.push(i);
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v: adj[u]) {
			--indeg[v];
			if(indeg[v]==0)
				q.push(v);
		}
		st.push_back(u);
	}

	dp[0]=1;
	for(int u: st) {
		for(int v: adj[u]) {
			dp[v]+=dp[u];
			dp[v]%=M;
		}
	}
	cout << dp[n-1];

	return 0;
}
