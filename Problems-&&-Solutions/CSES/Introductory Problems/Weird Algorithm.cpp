/*
Problem Statement: https://cses.fi/problemset/task/1068/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

ll n;

void solve() {
	cin >> n;
	while(n^1) {
		cout << n << " ";
		if(n&1)
			n=n*3+1;
		else
			n/=2;
	}
	cout << n;
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
