/*
Problem Statement: https://cses.fi/problemset/task/1618/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

void solve() {
	int n;
	cin >> n;
	int ans=0;
	for(int i=1; n/pow(5, i); ++i)
		ans+=n/pow(5, i);
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
