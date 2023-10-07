/*
Problem Statement: https://cses.fi/problemset/task/1069/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

string s;

void solve() {
	cin >> s;
	int cnt=1, ans=0;
	for(int i=0; i<s.size()-1; ++i) {
		if(s[i]==s[i+1])
			++cnt;
		else
			ans=max(ans, cnt), cnt=1;
	}
	ans=max(ans, cnt);
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
