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
using ll=long long;

const int mxN=1e2, mxX=1e6, M=1e9+7;
int n, x, c[mxN+1], dp[mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> c[i];

	dp[0]=1;
	for(int i=1; i<=n; ++i)
		for(int j=c[i]; j<=x; ++j)
			dp[j]=(dp[j]+dp[j-c[i]])%M;
	cout << dp[x];

	return 0;
}
