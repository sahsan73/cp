#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int INF=1e9+5;
const int mod=1e9+7;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vt<int> arr(n);
	for(int i=0; i<n; ++i) cin >> arr[i];

	for(int i=0; i<n-1; ++i) {
		if(abs(arr[i]-arr[i+1])==1) {
			cout << arr[i] << ' ';
		} else if(arr[i]<arr[i+1]) {
			for(int j=arr[i]; j<arr[i+1]; ++j)
				cout << j << ' ';
		} else {
			for(int j=arr[i]; j>arr[i+1]; --j)
				cout << j << ' ';
		}
	}
	cout << arr[n-1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; // cin >> t;
	while(t--) solve();
	return 0;
}
