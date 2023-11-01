/*
Problem Statement: https://cses.fi/problemset/task/1158/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: 0/1 KNAPSACK
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3, mxX=1e5;
int n, x, h[mxN+1], s[mxN+1], dp[mxN+1][mxX+1];

void solve() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> h[i];
	for(int i=1; i<=n; ++i)
		cin >> s[i];
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			dp[i][j]=dp[i-1][j];
			if(j>=h[i])
				dp[i][j]=max(dp[i][j], s[i]+dp[i-1][j-h[i]]);
		}
	}
	cout << dp[n][x];
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
