/*
Problem Statement: https://cses.fi/problemset/task/1638/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3, M=1e9+7;
int n, dp[mxN][mxN];
string s[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> s[i];
	dp[0][0]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(i)
				dp[i][j]+=dp[i-1][j];
			if(j)
				dp[i][j]+=dp[i][j-1];
			dp[i][j]%=M;
			if(s[i][j]=='*')
				dp[i][j]=0;
		}
	}
	cout << dp[n-1][n-1];
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3, M=1e9+7;
int n, dp[mxN+1][mxN+1];
string s[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> s[i];
	dp[1][1]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			dp[i][j]=max(dp[i][j], (dp[i-1][j]+dp[i][j-1])%M);
			if(s[i-1][j-1]=='*')
				dp[i][j]=0;
		}
	}
	cout << dp[n][n];
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
