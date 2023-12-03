/*
Problem Statement: https://cses.fi/problemset/task/1093
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e2, mxX=mxN*(mxN+1)/2, M=1e9+7;
int n, x;
ll dp[mxX+1];

int main() {
	cin >> n;
	x=n*(n+1)/2;
	if(x&1) {
		cout << 0;
		return 0;
	}

	dp[0]=1;
	x/=2; // target sum
	for(int i=1; i<=n; ++i)
		for(int j=x; j>=i; --j)
			dp[j]=(dp[j]+dp[j-i])%M;
	cout << dp[x]*((M+1)/2)%M; // IMPORTANT

	return 0;
}
