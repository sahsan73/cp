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

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> t[i][0] >> t[i][1];

	sort(t, t+n, [](auto &p, auto &q){
		return p[1]<q[1];
	});
	int cnt=1;
	int a=t[0][0], b=t[0][1];
	for(int i=1; i<n; ++i) {
		int x=t[i][0], y=t[i][1];
		if(x<b)
			continue;
		++cnt;
		a=x, b=y;
	}
	cout << cnt;

	return 0;
}
