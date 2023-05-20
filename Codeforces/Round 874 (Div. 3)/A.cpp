#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int INF=1e9+5;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n;
string s;

void solve() {
	cin >> n >> s;
	unordered_set<string> st;
	for(int i=0; i<n-1; ++i) 
		st.insert(s.substr(i,2));
	cout << sz(st) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
