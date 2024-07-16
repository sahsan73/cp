////////////// C++ STL ///////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array
const int mxN=1e6, M=1e9+7;
int n, a[mxN];
string s;

void solve() {
	cin >> s;
	sort(s.begin(), s.end());
	set<string> st;
	do {
		st.insert(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << st.size() << "\n";
	for(string t: st)
		cout << t << "\n";
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

///////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array
const int mxN=2e5;
string s;

void dfs(string &s, int i, set<string> &st) {
	if(i>=s.size()) {
		st.insert(s);
		return;
	}
	for(int j=i; j<s.size(); ++j) {
		swap(s[i], s[j]);
		dfs(s, i+1, st);
		swap(s[i], s[j]);
	}
}

void solve() {
	cin >> s;
	sort(s.begin(), s.end());
	set<string> st;
	dfs(s, 0, st);
	cout << st.size() << "\n";
	for(string t: st)
		cout << t << "\n";
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

///////////////////////////////////////////////////////////////
// I am trying to find a solution without using set....!!
