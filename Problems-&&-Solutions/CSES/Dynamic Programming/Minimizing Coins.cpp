/*
Problem Statement: https://cses.fi/problemset/task/1634
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Space optimized bottom-up approach
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e2, mxX=1e6;
int n, x, c[mxN+1], dp[mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> c[i];
	
	// dp[j] --> minimum no. of coins required to produce money j
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			if(j>=c[i])
				dp[j]=min(dp[j], 1+dp[j-c[i]]);
		}
	}
	if(dp[x]<1e9)
		cout << dp[x];
	else
		cout << -1;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6;
int n, x, c[mxN+1], dp[mxN+1][mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> c[i];
	
	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<=n; ++i)
		dp[i][0]=0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			int exclude=dp[i-1][j];
			int include=(j>=c[i])?1+dp[i][j-c[i]]:1e9;
			dp[i][j]=min(exclude, include);
		}
	}
	if(dp[n][x]<1e9)
		cout << dp[n][x];
	else
		cout << -1;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: 0/N (UNBOUNDED) KNAPSACK
    - Implementation: Top-Down (Recursion + Memoization)

VERDICT: TLE
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxX=1e6;
int n, x, c[mxN], dp[mxN][mxX+1];

int dfs(int i, int x) {
	if(i<0)
		return 0x3f3f3f3f;
	if(x==0)
		return 0;
	if(dp[i][x]<1e9)
		return dp[i][x];

	int exclude=dfs(i-1, x);
	int include=(x>=c[i])?1+dfs(i, x-c[i]):0x3f3f3f3f;
	return dp[i][x]=min(exclude, include);
}

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> c[i];

	memset(dp, 0x3f, sizeof(dp));
	cout << dfs(n-1, x);

	return 0;
}
