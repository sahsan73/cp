/*
Problem Statement: https://cses.fi/problemset/task/1637
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: GREEDY
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e6;
int n, dp[mxN+1];

void solve() {
	cin >> n;
	int cnt=0;
	while(n>0) {
		string s=to_string(n);
		int mx=*max_element(s.begin(), s.end())-'0';
		n-=mx;
		++cnt;
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DP
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e6;
int n, dp[mxN+1];

void solve() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		dp[i]=1e9;
		int x=i;
		while(x) {
			dp[i]=min(dp[i], 1+dp[i-x%10]);
			x/=10;
		}
	}
	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
