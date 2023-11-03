/*
Problem Statement: https://cses.fi/problemset/task/1745

Approach: 0/1 Knapsack
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=100, mxK=1e5;
int n, a[mxN+1], dp[mxN+1][mxK+1];

void solve() {
	cin >> n;
	int s=0;
	for(int i=1; i<=n; ++i)
		cin >> a[i], s+=a[i];
	for(int i=0; i<=n; ++i)
		dp[i][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=s; ++j) {
			dp[i][j]=dp[i-1][j];
			if(j>=a[i])
				dp[i][j]|=dp[i-1][j-a[i]];
		}
	}
	int cnt=0;
	for(int j=1; j<=s; ++j)
		cnt+=dp[n][j];
	cout << cnt << "\n";
	for(int j=1; j<=s; ++j)
		if(dp[n][j])
			cout << j << " ";
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
