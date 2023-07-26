#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=50;
int n;
char s[mxN];

void solve() {
	cin >> n >> s;
	unordered_set<string> st;
	for(int i=0; i<n-1; ++i)
		st.insert(string(1, s[i])+string(1, s[i+1]));
	cout << sz(st) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
