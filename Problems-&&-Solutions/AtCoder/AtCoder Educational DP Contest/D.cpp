/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_d
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e2, mxW=1e5;
int n, wt, w[mxN+1], v[mxN+1];
ll dp[mxN+1][mxW+1];

int main() {
	cin >> n >> wt;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> v[i];
	
	// dp[i][j] --> maximum value with items [0,...,i] and weight j
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=wt; ++j) {
			ll exclude=dp[i-1][j];
			ll include=(j>=w[i])?v[i]+dp[i-1][j-w[i]]:0;
			dp[i][j]=max(exclude, include);
		}
	}
	cout << dp[n][wt];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down (Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e2, mxW=1e5;
int n, wt, w[mxN], v[mxN];
ll dp[mxN][mxW+1];

ll dfs(int i=n-1, int j=wt) {
	if(i<0)
		return 0;
	if(~dp[i][j])
		return dp[i][j];
	
	ll exclude=dfs(i-1, j);
	ll include=(j>=w[i])?v[i]+dfs(i-1, j-w[i]):0;
	return dp[i][j]=max(exclude, include);
}


int main() {
	cin >> n >> wt;
	for(int i=0; i<n; ++i)
		cin >> w[i] >> v[i];

    // dp[i][j] --> maximum value in [0,....,i] with maximum weight j
	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
