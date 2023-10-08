/*
Problem Statement: https://cses.fi/problemset/task/2165/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

int n;
vector<ar<int, 2>> a;

void dfs(int n, int from, int aux, int to) {
	if(n==0)
		return;
	dfs(n-1, from, to, aux);
	a.push_back({from, to});
	dfs(n-1, aux, from, to);
}

void solve() {
	cin >> n;
	dfs(n, 1, 2, 3);
	cout << a.size() << "\n";
	for(ar<int, 2> p: a)
		cout << p[0] << " " << p[1] << "\n";
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
