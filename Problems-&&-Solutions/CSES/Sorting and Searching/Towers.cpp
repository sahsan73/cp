/*
Problem Statement: https://cses.fi/problemset/task/1073
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, k[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> k[i];
	vector<int> a={k[0]};
	for(int i=1; i<n; ++i) {
		if(k[i]>=a.back())
			a.push_back(k[i]);
		else {
			int j=upper_bound(a.begin(), a.end(), k[i])-a.begin();
			a[j]=k[i];
		}
	}
	cout << a.size();
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
