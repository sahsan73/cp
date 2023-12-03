/*
Problem Statement: https://cses.fi/problemset/task/1634
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e2, mxX=1e6;
int n, x, c[mxN+1], dp[mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> c[i];

	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=1; i<=n; ++i)
		for(int j=c[i]; j<=x; ++j)
			dp[j]=min(dp[j], 1+dp[j-c[i]]);
	cout << (dp[x]<1e9?dp[x]:-1);

	return 0;
}
