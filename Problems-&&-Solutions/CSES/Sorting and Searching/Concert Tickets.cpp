/*
Problem Statement: https://cses.fi/problemset/task/1091
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, m;

void solve() {
	cin >> n >> m;
	set<ar<int, 2>> st;
	for(int i=0, h; i<n; ++i) {
		cin >> h;
		st.insert({h, i});
	}
	for(int i=0, t; i<m; ++i) {
		cin >> t;
		auto it=st.lower_bound({t+1, 0});
		//cout << (*it)[0] << ", " << (*it)[1] << "\n";
		if(it==st.begin())
			cout << "-1\n";
		else {
			--it;
			//cout << (*it)[0] << ", " << (*it)[1] << "\n";
			cout << (*it)[0] << "\n";
			st.erase(it);
		}
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
