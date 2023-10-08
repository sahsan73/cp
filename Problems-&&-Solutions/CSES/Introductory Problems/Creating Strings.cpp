/*
Problem Statement: https://cses.fi/problemset/task/1622/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

string s;
vector<string> a;

void dfs(int i) {
	if(i==s.size()) {
		a.push_back(s);
		return;
	}
	for(int j=i; j<s.size(); ++j) {
		swap(s[i], s[j]);
		dfs(i+1);
		swap(s[i], s[j]);
	}
}

void solve() {
	cin >> s;
	dfs(0);

	set<string> st(a.begin(), a.end());
	cout << st.size() << "\n";
	for(auto &s1: st)
		cout << s1 << "\n";
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
