/*
Problem Statement: https://cses.fi/problemset/task/1744
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e2;
int a, b, dp[mxN+1][mxN+1];

void solve() {
	cin >> a >> b;
	for(int i=0; i<=a; ++i) {
		for(int j=0; j<=b; ++j) {
			if(i==j) {
				// they're already squares
				dp[i][j]=0;
			} else {
				dp[i][j]=1e9;
				// horizontal cuts
				for(int k=1; k<i; ++k)
					dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
				// vertical cuts
				for(int k=1; k<j; ++k)
					dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
		}
	}
	cout << dp[a][b];
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
