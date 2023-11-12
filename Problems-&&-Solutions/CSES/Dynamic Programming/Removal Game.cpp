/*
Problem Statement: https://cses.fi/problemset/task/1097
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: FIND MAX DIFFERENCE
Implementation: Iterative
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e3;
int n, x[mxN];
ll s, dp[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i], s+=x[i];

	// dp[i][j] --> max s1-s2 in range [i...j]
	// dp[i][j] = max(x[i]-dp[i+1][j], x[j]-dp[i][j-1])
	for(int i=n-1; ~i; --i) {
		for(int j=i; j<n; ++j) {
			if(i==j)
				dp[i][j]=x[i];
			else
				dp[i][j]=max(x[i]-dp[i+1][j], x[j]-dp[i][j-1]);
		}
	}
	cout << (s+dp[0][n-1])/2;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: FIND MAX DIFFERENCE
Implementation: Recursive
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e3;
int n, x[mxN];
ll s, dp[mxN][mxN];

ll dfs(int i=0, int j=n-1) {
	if(i>j)
		return 0;
	if(dp[i][j]>=-1e18)
		return dp[i][j];
	return dp[i][j]=max(x[i]-dfs(i+1, j), x[j]-dfs(i, j-1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i], s+=x[i];
	
	// dp[i][j] --> max s1-s2 in range [i...j]
	// dp[i][j] = max(x[i]-dp[i+1][j], x[j]-dp[i][j-1])
	memset(dp, 0xc0, sizeof(dp));
	cout << (s+dfs())/2;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DIRECTLY CALCULATE MAX SCORES
Implementation: Iterative
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e3;
int n, x[mxN];
ar<ll, 2> dp[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	
	// dp[i][j] --> {s1, s2}, max scores of player1 and player2
	// in the range [i...j]
	for(int i=n-1; ~i; --i) {
		for(int j=i; j<n; ++j) {
			ar<ll, 2> tr;
			if(i==j)
				tr={x[i], 0};
			else {
				if(dp[i+1][j][1]+x[i]>dp[i][j-1][1]+x[j])
					tr={dp[i+1][j][1]+x[i], dp[i+1][j][0]};
				else
					tr={dp[i][j-1][1]+x[j], dp[i][j-1][0]};
			}
			dp[i][j]=tr;
		}
	}
	cout << dp[0][n-1][0];

	return 0;
}
