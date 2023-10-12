/*
Problem Statement: https://cses.fi/problemset/task/1090
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x, p[mxN];

void solve() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> p[i];
	sort(p, p+n);
	int a=0;
	for(int i=0, j=n-1; i<=j; --j) {
		if(p[i]+p[j]<=x)
			++i;
		++a;
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
