/*
Problem Statement: https://codeforces.com/problemset/problem/910/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, d, dp[100];
string s;

void solve() {
	cin >> n >> d >> s;
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=0; i<n; ++i) {
		if(s[i]=='0'||dp[i]>=1e9)
			continue;
		for(int j=1; j<=d; ++j) {
			if(i+j<n&&s[i+j]=='1')
				dp[i+j]=min(dp[i+j], dp[i]+1);
		}
	}
	cout << (dp[n-1]<1e9?dp[n-1]:-1);
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
