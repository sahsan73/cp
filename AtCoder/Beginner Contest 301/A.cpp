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
	int n; string s;
	cin >> n >> s;

	int t=0, a=0;
	for(int i=0; i<n; ++i) {
		if(s[i]=='T') ++t;
		else ++a;
	}

	if(t>a) {
		cout << 'T' << '\n';
	} else if(t<a) {
		cout << 'A' << '\n';
	} else {
		for(int i=0; i<n; ++i) {
			if(s[i]=='T') {
				--t;
				if(!t) {
					cout << 'T' << '\n';
					return;
				}
			} else {
				--a;
				if(!a) {
					cout << 'A' << '\n';
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; // cin >> t;
	while(t--) solve();
	return 0;
}
