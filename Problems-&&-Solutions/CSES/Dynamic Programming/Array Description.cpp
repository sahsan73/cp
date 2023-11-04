/*
Problem Statement: https://cses.fi/problemset/task/1746
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, mxM=100, M=1e9+7;
int n, m, a[mxN], dp[mxN+1][mxM+2];

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n; ++i) {
		if(i==0) {
			if(a[i]==0)
				for(int j=1; j<=m; ++j)
					dp[0][j]=1;
			else
				dp[0][a[i]]=1;
		} else {
			if(a[i]==0)
				for(int j=1; j<=m; ++j)
					dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%M+dp[i-1][j+1])%M;
			else {
				for(int j=1; j<=m; ++j)
					if(j^a[i])
						dp[i][j]=0;
				dp[i][a[i]]=((dp[i-1][a[i]-1]+dp[i-1][a[i]])%M+dp[i-1][a[i]+1])%M;
			}
		}
	}
	int ans=0;
	for(int j=1; j<=m; ++j)
		ans=(ans+dp[n-1][j])%M;
	cout << ans;
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
