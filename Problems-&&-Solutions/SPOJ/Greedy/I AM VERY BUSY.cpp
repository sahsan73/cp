/*
Problem Statement: https://www.spoj.com/problems/BUSYMAN/

Standard Greedy Algorithm - An Activity Selection Problem / Scheduling Intervals

In other words - find the maximum number of non-overlapping intervals.
*/
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e5;
int n;
ar<int, 2> a[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i][0] >> a[i][1];

	sort(a, a+n, [](auto &a1, auto &a2){
		return a1[1]<a2[1];
	});

	int cnt=1;
	int s1=a[0][0], f1=a[0][1];
	for(int i=1; i<n; ++i) {
		int s2=a[i][0], f2=a[i][1];
		if(s2<f1)
			continue;
		++cnt;
		s1=s2, f1=f2;
	}
	cout << cnt << "\n";
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
