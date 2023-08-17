/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_b
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, k, h[mxN], dp[mxN];

int main() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> h[i];
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=0; i<n; ++i) {
		for(int j=1; j<=k; ++j) {
			if(i+j>=n)
				break;
			dp[i+j]=min(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
		}
	}
	cout << dp[n-1];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, k, h[mxN], dp[mxN];

int dfs(int i=0) {
	if(i==n-1)
		return 0;
	if(dp[i]<1e9)
		return dp[i];

	for(int j=1; j<=k; ++j) {
		if(i+j<n)
			dp[i]=min(dp[i], abs(h[i+j]-h[i])+dfs(i+j));
	}
	return dp[i];
}


int main() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> h[i];

	memset(dp, 0x3f, sizeof(dp));
	cout << dfs();

	return 0;
}
