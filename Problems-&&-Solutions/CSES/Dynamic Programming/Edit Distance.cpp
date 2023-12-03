/*
Problem STatement: https://cses.fi/problemset/task/1639
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
IMPLEMENTATION: BOTTOM-UP
	- C style string implementation
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3;
int n, m, dp[mxN+1][mxN+1];
char s[mxN+2], t[mxN+2];

int main() {
	cin >> s+1 >> t+1;

	n=strlen(s+1), m=strlen(t+1);
	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<=n; ++i)
		dp[i][0]=i;
	for(int j=1; j<=m; ++j)
		dp[0][j]=j;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(s[i]==t[j])
				dp[i][j]=dp[i-1][j-1];
			else {
				//                 add        remove      replace
				dp[i][j]=1+min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
			}
		}
	}
	cout << dp[n][m];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
IMPLEMENTATION: BOTTOM-UP
	- C++ style string implementation
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3;
int n, m, dp[mxN+1][mxN+1];
string s, t;

int main() {
	cin >> s >> t;

	n=s.size(), m=t.size();
	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<=n; ++i)
		dp[i][0]=i;
	for(int j=1; j<=m; ++j)
		dp[0][j]=j;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1];
			else {
				//                 add        remove      replace
				dp[i][j]=1+min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
			}
		}
	}
	cout << dp[n][m];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
IMPLEMENTATION: TOP-DOWN
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3;
int n, m, dp[mxN+1][mxN+1];
string s, t;

int dfs(int i=n, int j=m) {
	if(i==0)
		return j;
	if(j==0)
		return i;
	if(~dp[i][j])
		return dp[i][j];
	
	if(s[i-1]==t[j-1])
		return dp[i][j]=dfs(i-1, j-1);
	//                         add        remove       replace
	return dp[i][j]=1+min({dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1)});
}

int main() {
	cin >> s >> t;

	n=s.size(), m=t.size();
	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
