/*
Problem Statement: https://cses.fi/problemset/task/1093
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=500, mxS=1.3e5, M=1e9+7;
int n;
ll dp[mxN+1][mxS];

void solve() {
	cin >> n;
	int s=n*(n+1)/2;
	if(s&1) {
		cout << 0;
		return;
	}
	s/=2;
	for(int i=0; i<=n; ++i)
		dp[i][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=s; ++j) {
			dp[i][j]=dp[i-1][j];
			if(j>=i)
				dp[i][j]+=dp[i-1][j-i];
			dp[i][j]%=M;
		}
	}
	cout << dp[n][s]*((M+1)/2)%M; // IMPORTANT
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
