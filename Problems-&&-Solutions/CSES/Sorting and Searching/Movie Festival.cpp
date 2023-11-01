/*
Problem Statement: https://cses.fi/problemset/task/1629

APPROACH: GREEDY
    - Maximum number of NON-OVERLAPPING intervals.
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n;
ar<int, 2> t[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> t[i][0] >> t[i][1];
	}
	sort(t, t+n, [](ar<int, 2> x, ar<int, 2> y) {
		return x[1]<y[1];
	});
	int cnt=1;
	for(int i=1, b=t[0][1]; i<n; ++i) {
		if(b<=t[i][0]) {
			b=t[i][1];
			++cnt;
		}
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
