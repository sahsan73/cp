#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const char *s2="codeforces";
char s[11];

void solve() {
	cin >> s;
	int cnt=0;
	for(int i=0; i<10; ++i) {
		if(s[i]!=s2[i])
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
