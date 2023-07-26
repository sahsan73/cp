#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=200;
int n, m, d[mxN];

void solve() {
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	for(int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		++d[u], ++d[v];
	}

	unordered_map<int, int> mp;
	for(int i=0; i<n; ++i)
		++mp[d[i]];
	vt<int> dc; // degree count
	for(auto &p: mp)
		dc.pb(p.second);

	sort(all(dc));
	if(sz(dc)==3)
		cout << dc[1] << " " << dc[2]/dc[1] << "\n";
	else
		cout << dc[0]-1 << " " << dc[1]/(dc[0]-1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
