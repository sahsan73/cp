#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
ll n, b[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n-1; ++i)
		cin >> b[i];
	
	ll x=0;
	unordered_set<int> st;
	for(int i=0; i<n-1; ++i) {
		ll t=b[i]-x;
		if(1<=t&&t<=n)
			st.insert(t);
		x=b[i];
	}

	if((b[n-2]<=n*(n+1)/2)&&((sz(st)==n-2&&b[n-2]==n*(n+1)/2)||(sz(st)==n-1))) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
