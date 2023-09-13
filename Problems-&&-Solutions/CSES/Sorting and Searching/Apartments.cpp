/*
Problem Statement: https://cses.fi/problemset/task/1084
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, m, k;
ll a[mxN], b[mxN];

int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<m; ++i)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+m);
	int cnt=0, i=0, j=0;
	while(i<n&&j<m) {
		if(b[j]<a[i]-k) {
			++j;
		} else if(a[i]-k<=b[j]&&b[j]<=a[i]+k) {
			++cnt;
			++i, ++j;
		} else {
			++i;
		}
	}
	cout << cnt;

	return 0;
}
