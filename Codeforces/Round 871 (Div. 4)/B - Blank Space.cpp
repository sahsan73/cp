#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i) cin >> arr[i];
 
	int mx=0, cnt=0;
	for(int i=0; i<n; ++i) {
		if(arr[i]) {
			mx=max(mx, cnt);
			cnt=0;
		} else {
			++cnt;
		}
	}
	cout << max(mx, cnt) << '\n';
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
