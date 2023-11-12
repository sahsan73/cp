/*
Problem Statement: https://cses.fi/problemset/task/1744
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e2;
int a, b, dp[mxN+1][mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	// dp[i][j]=minimum cuts required for ixj sheet
	for(int i=0; i<=a; ++i) {
		for(int j=0; j<=b; ++j) {
			if(i==j) // they're already squares
				dp[i][j]=0;
			else {
				dp[i][j]=1e9;
				// horizontal cuts
				for(int k=1; k<i; ++k)
					dp[i][j]=min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);

				// vertical cuts
				for(int k=1; k<j; ++k)
					dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
			}
		}
	}
	cout << dp[a][b];

	return 0;
}
