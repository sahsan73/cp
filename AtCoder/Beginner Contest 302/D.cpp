/*
APPROACH: BINARY SEARCH
    - Sort one of the arrays say A
    - Now iterate through B , for e.g., y belongs B
        - i. For each y, find x which is less than equal to d + y using Binary Search (if not found, skip ii)
        - ii. Check for the candidate x+y

COMPLEXITY:
    - TC = O(mlogn)
    - SC = O(1), not considering for input
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int INF=1e9+5;
const int mod=1e9+7;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, m;
ll d, ans;

void solve() {
	cin >> n >> m >> d;
	vt<ll> a(n), b(m);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) cin >> b[i];

	sort(all(a));
	auto find_pair=[&](ll t) {
		ll res=-INF;
		int lo=0, hi=n-1;
		while(lo<=hi) {
			int m=(lo+hi)/2;
			if(t==a[m]) return t;

			if(t<a[m]) {
				hi=m-1;
			} else {
				res=max(ans, a[m]);
				lo=m+1;
			}
		}
		return res;
	};

	ll ans=-1;
	for(auto &y: b) {
		ll x=find_pair(y+d);
		if(x==-INF) continue;
		
		if(y-x<=d) ans=max(ans, x+y);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; // cin >> t;
	while(t--) solve();
	return 0;
}
