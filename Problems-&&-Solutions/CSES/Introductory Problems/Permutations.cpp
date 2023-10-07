/*
Problem Statement: https://cses.fi/problemset/task/1070/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x[mxN];

void solve() {
	cin >> n;
	if(n==2||n==3) {
		cout << "NO SOLUTION";
		return;
	}

	vector<int> a;
	for(int i=2; i<=n; i+=2)
		a.push_back(i);
	for(int i=1; i<=n; i+=2)
		a.push_back(i);
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
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
