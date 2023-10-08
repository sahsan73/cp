/*
Problem Statement: https://cses.fi/problemset/task/1754/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

int n, a, b;

void solve() {
	cin >> a >> b;
	if((a+b)%3==0&&2*a>=b&&2*b>=a)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
