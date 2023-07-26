#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=100;
int n, a[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	int ans=0, cnt=0;
	for(int i=0; i<n; ++i) {
		if(a[i]) {
			ans=max(ans, cnt);
			cnt=0;
		} else {
			++cnt;
		}
	}
	ans=max(ans, cnt);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
