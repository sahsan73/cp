/*
Considering the cases when array contains elements of both parities, i.e., even and odd
    - It is NOT possible to make all numbers even, ai - aj <= 0 where ai is the smallest odd number which violates being the beautiful array.
      and obviously both the numbers ai and aj have to be odd in order to change the parity to even.

    - We can change all the numbers to odd if-and-only-if the smallest number in the array is odd since EVEN - ODD ==> ODD.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, arr[mxN], c1, c2;

void solve() {
	cin >> n;
	int c1=0, c2=0, mn=1e9;
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		mn=min(mn, arr[i]);
		if(arr[i]&1)
			++c1;
		else
			++c2;
	}

	if(c1==0||c2==0||(mn&1))
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
