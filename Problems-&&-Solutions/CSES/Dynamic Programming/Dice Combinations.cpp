/*
Problem Statement: https://cses.fi/problemset/task/1633
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e6, M=1e9+7;
int n, dp[mxN+1];

void solve() {
	cin >> n;
	dp[0]=1;
	for(int i=1; i<=n; ++i)
		for(int d=1; d<=6; ++d)
			if(i>=d) {
				dp[i]+=dp[i-d];
				dp[i]%=M;
			}
	cout << dp[n];
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
