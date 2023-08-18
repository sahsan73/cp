/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_e
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up(Iteration + Tabulation)

If we are going to apply standard Knapsack procedure, our Time complexity will be O(100*10^9) and also CANNOT allocate memory (100 * 10^9) for 
caching the result this time. So we are going to cache the result of minimum total weight in [0,.....,i] with value exactly j
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e2, mxV=1e5; // mxV --> 100*(10^3)
int n, wt, w[mxN+1], v[mxN+1], dp[mxN+1][mxV+1];

int main() {
	cin >> n >> wt;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> v[i];
	
	// dp[i][j] --> min total weight of items [0,...,i] with total value exactly j
	memset(dp, 0x3f, sizeof(dp));
    // if we do NOT take any elements (i.e., for i = 0), we cannot have total value > 0 so we set minimum weight (i=0 and j=1 to 10^5) to infinity
    // but we can have minimum weight 0 if exclude every element (i.e., i=0 to n and j(value) = 0)
	for(int i=0; i<=n; ++i)
		dp[i][0]=0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=mxV; ++j) {
			int exclude=dp[i-1][j];
			int include=(j>=v[i])?w[i]+dp[i-1][j-v[i]]:0x3f3f3f3f;
			dp[i][j]=min(exclude, include);
		}
	}

	int a=0;
	for(int j=1; j<=mxV; ++j) {
		if(dp[n][j]<=wt)
			a=max(a, j);
	}
	cout << a;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down
*/
