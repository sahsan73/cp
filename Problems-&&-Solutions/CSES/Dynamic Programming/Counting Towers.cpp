/*
Problem Statement: https://cses.fi/problemset/task/2413
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e6, M=1e9+7;
int q, n;
ll dp[mxN+1][2];

void solve() {
	// dp[0][i]=no. of ways, towers with i height can be built(from i-1 height tower) with when we have two blocks of width 1
	// dp[1][i]=no. of ways towers, with i height can be built(from i-1 height tower) with when we have one block of width 2
	// total ways for i height tower = dp[0][i] + dp[1][i]
	dp[1][0]=dp[1][1]=1;
	for(int i=2; i<=mxN; ++i) {
		// we have two blocks of width 1
		dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%M;

		// we have one block of width 2
		dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%M;
	}

	cin >> q;
	while(q--) {
		cin >> n;
		cout << (dp[n][0]+dp[n][1])%M << "\n";
	}
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
