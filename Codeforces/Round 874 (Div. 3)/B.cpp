#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int INF=1e9+5;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, k;

void solve() {
	cin >> n >> k;
	vt<pair<int,int>> a(n);
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		a[i]=make_pair(x, i);
	}
	vt<int> b(n);
	for(int i=0; i<n; ++i) cin >> b[i];

	sort(all(a));
	sort(all(b));

	vt<int> ans(n);
	for(int i=0; i<n; ++i) {
		ans[a[i].second]=b[i];
	}
	for(int i=0; i<n; ++i) cout << ans[i] << " ";
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
