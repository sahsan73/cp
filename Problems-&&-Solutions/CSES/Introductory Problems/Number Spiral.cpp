/*
Problem Statement: https://cses.fi/problemset/task/1071/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

ll x, y;

void solve() {
	cin >> y >> x;
	ll mx=max(x, y), mn=min(x, y);
	ll n=(mx-1)*(mx-1);
	if(mx&1)
		n+=(mn==x)?x:2*x-y;
	else
		n+=(mn==x)?2*y-x:y;
	
	cout << n << "\n";
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
