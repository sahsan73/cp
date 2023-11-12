/*
Problem Statement: https://cses.fi/problemset/task/2413
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e6, M=1e9+7;
int n;
ll dp[mxN+1][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// dp[i][j] --> no. of towers having height i with a
	// block of width j
	dp[1][1]=dp[1][2]=1;
	for(int i=2; i<=mxN; ++i) {
		dp[i][1]=(4*dp[i-1][1]+dp[i-1][2])%M;
		dp[i][2]=(2*dp[i-1][2]+dp[i-1][1])%M;
	}
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << (dp[n][1]+dp[n][2])%M << "\n";
	}
	return 0;
}
