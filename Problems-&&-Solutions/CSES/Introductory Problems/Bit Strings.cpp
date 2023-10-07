/*
Problem Statement: https://cses.fi/problemset/task/1617/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

void solve() {
	int n;
	cin >> n;
	ll a=1;
	for(int i=0; i<n; ++i)
		a=2*a%((int)1e9+7);
	cout << a;
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
