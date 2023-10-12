/*
Problem Statement: https://cses.fi/problemset/task/1084
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, m, k, a[mxN], b[mxN];

void solve() {
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<m; ++i)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int ans=0;
	for(int i=0, j=0; i<n&&j<m;) {
		if(a[i]-k<=b[j]&&b[j]<=a[i]+k)
			++ans, ++i, ++j;
		else if(a[i]<b[j])
			++i;
		else
			++j;
	}
	cout << ans;
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
