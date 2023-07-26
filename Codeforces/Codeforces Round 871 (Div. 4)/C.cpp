#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n;

void solve() {
	cin >> n;
	unordered_map<string, int> mp;
	mp["00"]=mp["10"]=mp["01"]=mp["11"]=1e9;
	for(int i=0, m; i<n; ++i) {
		string s;
		cin >> m >> s;
		mp[s]=min(mp[s], m);
	}

	int r1=mp["01"]+mp["10"], r2=mp["11"];
	cout << (min(r1, r2)>=1e9?-1:min(r1, r2)) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
