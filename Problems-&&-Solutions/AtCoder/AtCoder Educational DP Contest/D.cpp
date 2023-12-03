/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_d
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
SUPER SPACE OPTIMIZED BOTTOM-UP APPROACH
	- If we run the loop backward, then we can use the current row as previous row too...!

COMPLEXITY:
	- TC = O(n*x)
 	- SC = O(x)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=100, mxX=1e5;
int n, x, w[mxN+1], v[mxN+1];
ll dp[mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> v[i];
	
	// dp[i][j]=maximum values with first i items [0...i] having having knapsack capacity of j
	for(int i=1; i<=n; ++i) {
		for(int j=x; j>0; --j) {
			ll ex=dp[j]; // exclude
			ll in=(j>=w[i])?v[i]+dp[j-w[i]]:0; // include
			dp[j]=max(ex, in);
		}
	}
	cout << dp[x];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
SPACE OPTIMIZED BOTTOM-UP APPROACH
	- In dp array, to evaluate the maximum for current row, we were only accessing the previous row's values

COMPLEXITY:
	- TC = O(n*x)
 	- SC = O(2*x)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=100, mxX=1e5;
int n, x, w[mxN+1], v[mxN+1];
ll dp[2][mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> v[i];
	
	// dp[i][j]=maximum values with first i items [0...i] having having knapsack capacity of j
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			ll ex=dp[0][j]; // exclude
			ll in=(j>=w[i])?v[i]+dp[0][j-w[i]]:0; // include
			dp[1][j]=max(ex, in);
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
	}
	cout << dp[1][x];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)

COMPLEXITY:
	- TC = O(n*x)
 	- SC = O(n*x)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=100, mxX=1e5;
int n, x, w[mxN+1], v[mxN+1];
ll dp[mxN+1][mxX+1];

int main() {
	cin >> n >> x;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> v[i];

	// dp[i][j] = maximum values with first i items [0.....i] having knapsack capacity of j
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=x; ++j) {
			ll ex=dp[i-1][j]; // exclude
			ll in=(j>=w[i])?v[i]+dp[i-1][j-w[i]]:0; // include
			dp[i][j]=max(ex, in);
		}
	}
	cout << dp[n][x];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down (Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=100, mxX=1e5;
int n, x, w[mxN], v[mxN];
ll dp[mxN][mxX+1];

ll knapsack(int i=n-1, int j=x) {
	if(i<0||j==0)
		return 0;
	if(~dp[i][j])
		return dp[i][j];

	ll ex=knapsack(i-1, j);
	ll in=(j>=w[i])?v[i]+knapsack(i-1, j-w[i]):0;
	return dp[i][j]=max(ex, in);
}

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> w[i] >> v[i];
	
	memset(dp, -1, sizeof(dp));
	cout << knapsack();

	return 0;
}
