/*
Problem Statement: https://cses.fi/problemset/task/1623/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

int n, p[20];
ll w, a;

void dfs(int i, ll w2, ll t) {
	if(i<0||t==0) {
		a=min(a, w-2*w2);
		return;
	}
	dfs(i-1, w2, t);
	if(p[i]<=t)
		dfs(i-1, w2+p[i], t-p[i]);
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i], w+=p[i];
	a=1e18;
	dfs(n-1, 0ll, w/2);
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
