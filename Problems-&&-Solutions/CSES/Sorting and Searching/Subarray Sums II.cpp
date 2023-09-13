/*
Problem Statement: https://cses.fi/problemset/task/1661
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n;
ll x, a[mxN];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	
	map<ll, ll> mp;
	mp[0]=1;
	ll cnt=0, s=0;
	for(int i=0; i<n; ++i) {
		s+=a[i];
		cnt+=mp[s-x];
		++mp[s];
	}
	cout << cnt;

	return 0;
}
