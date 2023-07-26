#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, a[mxN], b[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i], b[i]=a[i];
	sort(b, b+n);
	for(int i=0; i<n; ++i) {
		if((b[i]&1&&a[i]%2==0)||(b[i]%2==0&&a[i]&1)) {
			cout << "NO" << "\n";
			return;
		}
	}
	cout << "YES" << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
