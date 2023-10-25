/*
Problem Statemnt: https://cses.fi/problemset/task/1750/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, t[mxN], anc[mxN][30];

void solve() {
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> t[i], --t[i], anc[i][0]=t[i];
	for(int j=1; j<30; ++j)
		for(int i=0; i<n; ++i)
			anc[i][j]=anc[anc[i][j-1]][j-1];
	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		for(int j=29; ~j; --j)
			if((1<<j)&k)
				x=anc[x][j];
		cout << x+1 << "\n";
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
