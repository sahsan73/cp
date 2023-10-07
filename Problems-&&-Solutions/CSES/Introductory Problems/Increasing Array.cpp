/*
Problem Statement: https://cses.fi/problemset/task/1094/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	ll a=0;
	for(int i=1; i<n; ++i) {
		if(x[i]>=x[i-1])
			continue;
		a+=abs(x[i]-x[i-1]);
		x[i]=x[i-1];
	}
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
