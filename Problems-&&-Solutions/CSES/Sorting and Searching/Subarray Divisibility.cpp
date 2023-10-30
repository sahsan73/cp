/*
Problem Statement: https://cses.fi/problemset/task/1662

Resources:
https://leetcode.com/problems/subarray-sums-divisible-by-k/editorial/
https://usaco.guide/problems/cses-1662-subarray-divisibility/solution
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x, a[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	unordered_map<ll, int> mp;
	++mp[0];
	ll s=0, ans=0;
	for(int i=0; i<n; ++i) {
		//s=(s+a[i])%n; // if only +ve nums
		s=(s+a[i]%n+n)%n;
		ans+=mp[s];
		++mp[s];
	}
	cout << ans;
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
