/*
Problem Statement: https://cses.fi/problemset/task/1083/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
ll n, a[mxN];

void solve() {
	cin >> n;
	ll s=0ll;
	for(int i=0; i<n-1; ++i)
		cin >> a[i], s+=a[i];
	
	ll s2=n*(n+1)/2;
	cout << s2-s;
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
