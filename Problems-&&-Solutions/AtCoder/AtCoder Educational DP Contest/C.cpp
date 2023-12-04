/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_c
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up (Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, dp[mxN][3];
ar<int, 3> p[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i][0] >> p[i][1] >> p[i][2];

	dp[0][0]=p[0][0], dp[0][1]=p[0][1], dp[0][2]=p[0][2];
	for(int i=1; i<n; ++i) {
		// jth activity on ith day
		for(int j=0; j<3; ++j) {
			// kth activity on (i-1)th day
			for(int k=0; k<3; ++k) {
				if(k==j)
					continue;
				dp[i][j]=max(dp[i][j], p[i][j]+dp[i-1][k]);
			}
		}
	}
	cout << (*max_element(dp[n-1], dp[n-1]+3));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down (Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, dp[mxN][4];
ar<int, 3> p[mxN];

int dfs(int i=n-1, int j=-1) {
	if(i<0)
		return 0;
	if(~dp[i][j+1])
		return dp[i][j+1];
	
	int ans=0;
	for(int k=0; k<3; ++k) {
		if(k^j)
			ans=max(ans, p[i][k]+dfs(i-1, k));
	}
	return dp[i][j+1]=ans;
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i][0] >> p[i][1] >> p[i][2];

	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
