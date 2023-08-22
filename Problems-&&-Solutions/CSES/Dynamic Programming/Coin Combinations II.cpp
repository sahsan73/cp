/*
Problem Statement: https://cses.fi/problemset/task/1636

APPROACH: 0/N (UNBOUNDED) KNAPSACK - DYNAMIC PROGRAMMING
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6, M=1e9+7;
int n, x, c[mxN+1], dp[mxN+1][mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> c[i];
	
	for(int i=0; i<=n; ++i)
		dp[i][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			int exclude=dp[i-1][j];
			int include=(j>=c[i])?dp[i][j-c[i]]:0;
			dp[i][j]=(exclude+include)%M;
		}
	}
	cout << dp[n][x];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down

VERDICT: TLE

However, this solution is AC in LeetCode due to LOW constraints.
	- Problem Link: https://leetcode.com/problems/coin-change-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6, M=1e9+7;
int n, x, c[mxN], dp[mxN][mxX+1];

int dfs(int i, int x) {
	if(x==0)
		return 1;
	if(i<0)
		return 0;
	if(~dp[i][x])
		return dp[i][x];

	int exclude=dfs(i-1, x);
	int include=(x>=c[i])?dfs(i, x-c[i]):0;
	return dp[i][x]=(exclude+include)%M;
}

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	
	memset(dp, -1, sizeof(dp));
	cout << dfs(n-1, x);

	return 0;
}
