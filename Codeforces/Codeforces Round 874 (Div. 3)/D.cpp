/*
The first number in our resultant permutation will be p(r+1) if r<n e.g., [2, 3, 1, 5, 4] or pr if r==n e.g., [2, 3, 1, 4, 5]. So we
can easily fix our r index.

Determine the l index:
    - p[l] > p[0] so that after swapping we get the largest permutation.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e3;
int n, p[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i];

	int r=0;
	for(int i=0; i<n; ++i) {
		if(p[min(r+1, n-1)]<=p[min(i+1, n-1)])
			r=i;
	}

	vt<int> ans;
	for(int i=r+1; i<n; ++i)
		ans.pb(p[i]);
	ans.pb(p[r]); // segment [l...r] must contain atleast one element
	for(int i=r-1; ~i; --i) {
		if(p[i]>p[0])
			ans.pb(p[i]);
		else {
			for(int j=0; j<=i; ++j)
				ans.pb(p[j]);
		}
	}

	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
