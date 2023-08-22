/*
Problem Statement: https://cses.fi/problemset/task/1635

APPROACH: O/N(UNBOUNDED KNAPSACK)
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6, M=1e9+7;
int n, x, c[mxN], dp[mxX+1];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	
	dp[0]=1;
	for(int j=1; j<=x; ++j) {
		int res=0;
		for(int i=0; i<n; ++i) {
			if(j>=c[i]) {
				res+=dp[j-c[i]];
				res%=M;
			}
		}
		dp[j]=res;
	}
	cout << dp[x];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down(Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6, M=1e9+7;
int n, x, c[mxN], dp[mxX+1];

int dfs(int x) {
	if(x==0)
		return 1;
	if(~dp[x])
		return dp[x];

	int res=0;
	for(int i=0; i<n; ++i) {
		if(x>=c[i]) {
			res+=dfs(x-c[i]);
			res%=M;
		}
	}
	return dp[x]=res;
}

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> c[i];

	memset(dp, -1, sizeof(dp));
	cout << dfs(x);

	return 0;
}
