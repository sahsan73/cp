#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int INF=1e9+5;
const int mod=1e9+7;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

ll a, b;

void solve() {
	cin >> a >> b;
	ll cnt=a/b;
	if(a%b) ++cnt;
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; // cin >> t;
	while(t--) solve();
	return 0;
}
