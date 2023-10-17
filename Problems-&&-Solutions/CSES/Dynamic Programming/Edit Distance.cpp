/*
Problem STatement: https://cses.fi/problemset/task/1639
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e3;
int dp[mxN+1][mxN+1];
string s, t;

int dfs(int n, int m) {
	if(n==0)
		return m;
	if(m==0)
		return n;
	if(~dp[n][m])
		return dp[n][m];
	if(s[n-1]==t[m-1])
		return dp[n][m]=dfs(n-1, m-1);
	int x=dfs(n, m-1); // add
	int y=dfs(n-1, m); // remove
	int z=dfs(n-1, m-1); // replace
	return dp[n][m]=1+min({x, y, z});
}

void solve() {
	cin >> s >> t;
	memset(dp, -1, sizeof(dp));
	cout << dfs(s.size(), t.size());
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
