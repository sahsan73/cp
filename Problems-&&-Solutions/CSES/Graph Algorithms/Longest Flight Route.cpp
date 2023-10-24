/*
Problem Statement: https://cses.fi/problemset/task/1680/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, vis[mxN];
vector<int> adj[mxN], st;
ar<int, 3> dp[mxN];

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
	dp[0][2]=1; // dp[i][2] == true, the path is coming from starting point node 0
	for(int i=n-1; ~i; --i) {
		for(int j: adj[st[i]]) {
			if(dp[st[i]][2]&&dp[st[i]][0]+1>dp[j][0]) {
				dp[j][0]=dp[st[i]][0]+1;
				dp[j][1]=st[i];
				dp[j][2]=1;
			}
		}
	}
	if(!dp[n-1][2]) {
		cout << "IMPOSSIBLE";
		return;
	}
	vector<int> ans;
	for(int u=n-1; u^0; u=dp[u][1])
		ans.push_back(u);
	ans.push_back(0);
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int i=0; i<ans.size(); ++i)
		cout << ans[i]+1 << " ";
	cout << "\n";
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
