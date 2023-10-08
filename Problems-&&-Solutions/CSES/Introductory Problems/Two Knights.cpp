/*
Problem Statement: https://cses.fi/problemset/task/1072
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

void solve() {
	int n;
	cin >> n;
	for(int k=1; k<=n; ++k) {
		// a2 --> total no. of ways
		ll a1=k*k, a2=a1*(a1-1)/2;
		// total no. of ways knights can attack each other
		if(k>2)
			a2-=4*(k-1)*(k-2);
		cout << a2 << "\n";
	}
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
