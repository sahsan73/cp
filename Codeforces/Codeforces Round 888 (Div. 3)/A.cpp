#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
const int mxN=50;
int n, m, k, h, arr[mxN];
 
void solve() {
	cin >> n >> m >> k >> h;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
 
	int cnt=0;
	for(int i=0; i<n; ++i) {
		int x=abs(h-arr[i]);
		if(x==0||x%k)
			continue;
		if((x/k)<m)
			++cnt;
	}
	cout << cnt << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
