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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, M=1e9+7;
int n, m, vis[mxN];
vector<int> adj[mxN], st;
ar<int, 2> dp[mxN];

void dfs(int u) {
	vis[u]=1;
	for(int v: adj[u])
		if(!vis[v])
			dfs(v);
	st.push_back(u);
}

void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs(i);
	}
	dp[0][0]=dp[0][1]=1;
	for(int i=n-1; ~i; --i) {
		if(!dp[st[i]][1])
			continue;
		for(int j: adj[st[i]]) {
			dp[j][0]+=dp[st[i]][0];
			dp[j][0]%=M;
			dp[j][1]=1;
		}
	}
	cout << dp[n-1][0];
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
