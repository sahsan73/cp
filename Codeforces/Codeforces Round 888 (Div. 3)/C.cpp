#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, k, c[mxN];

void solve() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> c[i];
		
	//  left  right
	int k1=k, k2=k;
	if(c[0]==c[n-1]) {
		k1=k/2;
		k2=k-k1;
	}
	int i=0, cnt1=0;
	for(; i<n&&cnt1<k1; ++i) {
		if(c[i]==c[0])
			++cnt1;
	}
	int j=n-1, cnt2=0;
	for(; ~j&&cnt2<k2; --j) {
		if(c[j]==c[n-1])
			++cnt2;
	}
	cout << (i-1<j+1?"YES":"NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
