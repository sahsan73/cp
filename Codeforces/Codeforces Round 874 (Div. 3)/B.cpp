#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=1e5;
int n, k, a[mxN], b[mxN], ans[mxN];

void solve() {
	cin >> n >> k;
	vt<pair<int, int>> a2;
	for(int i=0; i<n; ++i)
		cin >> a[i], a2.pb({a[i], i});
	for(int i=0; i<n; ++i)
		cin >> b[i];

	sort(all(a2));
	sort(b, b+n);
	for(int i=0; i<n; ++i)
		ans[a2[i].second]=b[i];
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
