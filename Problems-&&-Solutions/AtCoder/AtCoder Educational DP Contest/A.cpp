/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_a
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up(Iteration + Tabulation)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, h[mxN], dp[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> h[i];
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0, dp[1]=abs(h[1]-h[0]);
	for(int i=2; i<n; ++i)
		dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	cout << dp[n-1];

	return 0;
}

// Errichto's Implementation
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, h[mxN], dp[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> h[i];
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=0; i<n; ++i) {
		for(int j: {i+1, i+2}) {
			if(j>=n)
				continue;
			dp[j]=min(dp[j], dp[i]+abs(h[j]-h[i]));
		}
	}
	cout << dp[n-1];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down (Recursion + Memoization)
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, h[mxN], dp[mxN];

int dfs(int i=0) {
	if(i==n-1)
		return 0;
	if(dp[i]!=-1)
		return dp[i];

	int jump_1=abs(h[i+1]-h[i])+dfs(i+1);
	int jump_2=(i<n-2)?abs(h[i+2]-h[i])+dfs(i+2):1e9;
	return dp[i]=min(jump_1, jump_2);
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> h[i];
	
	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
