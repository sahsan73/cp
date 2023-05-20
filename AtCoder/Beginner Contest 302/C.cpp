#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int INF=1e9+5;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int m, n;
unordered_set<string> st;

bool dfs(string &s, int cnt) {
	if(cnt==m) return 1;

	st.erase(s);
	for(int i=0; i<sz(s); ++i) {
		char orig=s[i];
		for(char ch='a'; ch<='z'; ++ch) {
			s[i]=ch;
			if(st.count(s) && dfs(s, cnt+1)) return 1;
		}
		s[i]=orig;
	}
	st.insert(s);
	return 0;
}

void solve() {
	cin >> m >> n;
	vt<string> arr(m);
	for(int i=0; i<m; ++i) {
		cin >> arr[i];
		st.insert(arr[i]);
	}

	for(auto &s: arr) {
		st.erase(s);
		if(dfs(s, 1)) {
			cout << "Yes" << '\n';
			return;
		}
		st.insert(s);
	}
	cout << "No" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; // cin >> t;
	while(t--) solve();
	return 0;
}
