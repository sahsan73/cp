/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_f
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)

COMPLEXITY:
    - TC = O(mn)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3;
int m, n, dp[mxN+1][mxN+1];
string s, t, a;

int main() {
	cin >> s >> t;
	m=s.size(), n=t.size();

    // compute LCS
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=n; ++j) {
			if(s[i-1]==t[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}

    // trace back solution
	int i=m, j=n;
	while(dp[i][j]) {
		if(s[i-1]==t[j-1]) {
			a+=s[i-1];
			--i, --j;
		} else {
			if(dp[i][j]==dp[i-1][j])
				--i;
			else
				--j;
		}
	}
	reverse(a.begin(), a.end());
	cout << a;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down(Recursion + Memoization)

COMPLEXITY:
    - TC = O(m*n), m = sz(s), and n = sz(t)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3;
int m, n, dp[mxN][mxN];
string s, t, a;

// compute LCS
int dfs(int i=m-1, int j=n-1) {
	if(i<0||j<0)
		return 0;
	if(~dp[i][j])
		return dp[i][j];

	if(s[i]==t[j])
		return dp[i][j]=1+dfs(i-1, j-1);
	return dp[i][j]=max(dfs(i-1, j), dfs(i, j-1));
}

// trace back the solution
void dfs2(int i=m-1, int j=n-1) {
	if(i<0||j<0)
		return;
	if(s[i]==t[j]) {
		a+=s[i];
		dfs2(i-1, j-1);
	} else {
		if(dfs(i, j)==dfs(i-1, j))
			dfs2(i-1, j);
		else
			dfs2(i, j-1);
	}
}

int main() {
	cin >> s >> t;
	m=s.size(), n=t.size();

	memset(dp, -1, sizeof(dp));
	dfs();
	dfs2();
	reverse(a.begin(), a.end());
	cout << a;

	return 0;
}
