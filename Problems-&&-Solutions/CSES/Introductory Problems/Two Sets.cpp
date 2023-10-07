/*
Problem Statement: https://cses.fi/problemset/task/1092/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

ll n, s;

void solve() {
	cin >> n;
	s=n*(n+1)/2;
	if(s&1) {
		cout << "NO";
		return;
	}

	s/=2;
	set<int> st1, st2;
	for(int i=n; i>0; --i) {
		if(s>=i)
			s-=i, st1.insert(i);
		else
			st2.insert(i);
	}
	cout << "YES" << "\n";
	cout << st1.size() << "\n";
	for(int x: st1)
		cout << x << " ";
	cout << "\n" << st2.size() << "\n";
	for(int x: st2)
		cout << x << " ";
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
