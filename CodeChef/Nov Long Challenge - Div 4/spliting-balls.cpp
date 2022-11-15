#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll mod=1e9+7, mxN=1e6;
ll dp[mxN+1];

void solve() {
	int n;	cin>>n;

	ll ans = 0;
	for(int i=0; i<n; ++i) {
		ll x; cin>>x;
			
		ans += dp[x];
		ans %= mod;
	}
	cout << (ans%mod) << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dp[0] = dp[1] = 1;
	for(int i=2; i<=mxN; ++i) {
		dp[i] = (i%mod) * (dp[i-1]%mod);
		dp[i] %= mod;
	}

	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
