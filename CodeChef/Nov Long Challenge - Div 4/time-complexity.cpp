#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()


void solve() {
	int x, y;
	cin >> x >> y;
	cout << ((x>y)?"YES":"NO") << endl;	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
