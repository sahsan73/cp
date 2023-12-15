# Modulo Sum
Problem Statement: <https://codeforces.com/problemset/problem/577/B>   

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6, mxM=1e3, M=1e9+7;
int n, m, a[mxN+1], dp[mxM+1][mxM+1];

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		cin >> a[i], a[i]%=m;

	// pigeon hole principle
	if(n>m) {
		cout << "YES";
		return 0;
	}

	// n<=m, 0/1 knapsack
	for(int i=1; i<=n; ++i)
		dp[i][a[i]]=1;
	for(int i=2; i<=n; ++i) {
		for(int j=0; j<m; ++j) {
			// exclude
			dp[i][j]|=dp[i-1][j];
			// include
			dp[i][j]|=dp[i-1][(j-a[i]+m)%m];
		}
	}
	cout << (dp[n][0]?"YES":"NO");

	return 0;
}
```
