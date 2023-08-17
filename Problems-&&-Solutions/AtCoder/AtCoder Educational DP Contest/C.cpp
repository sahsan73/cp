/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_c
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up (Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;

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
		// jjth activity on ith day
		for(int jj=0; jj<3; ++jj) {
			// jth activity on (i-1)th day
			for(int j=0; j<3; ++j) {
				if(j==jj)
					continue;
				dp[i][jj]=max(dp[i][jj], p[i][jj]+dp[i-1][j]);
			}
		}
	}
	cout << *max_element(dp[n-1], dp[n-1]+3);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down (Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e5;
int n, dp[mxN][4];
ar<int, 3> p[mxN];

// ith day, jth activity done on (i-1)th day
int dfs(int i=0, int j=-1) {
	if(i>=n)
		return 0;
	if(~dp[i][j+1])
		return dp[i][j+1];
	
	int res=0;
	for(int jj=0; jj<3; ++jj) {
		if(jj==j)
			continue;
		res=max(res, p[i][jj]+dfs(i+1, jj));
	}
	return dp[i][j+1]=res;
}


int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i][0] >> p[i][1] >> p[i][2];

	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
