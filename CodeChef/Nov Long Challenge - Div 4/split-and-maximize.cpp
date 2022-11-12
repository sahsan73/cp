#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll mod=998244353;
void solve() {
	int n;	cin>>n;

	ll sum = 0;
	for(int i=0; i<n; ++i) {
		ll x; cin>>x;
		sum += x;
		sum %= mod;
	}
	cout << ((sum%mod)*((sum-1)%mod))%mod << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
