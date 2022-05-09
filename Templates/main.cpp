#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const double pi = acos(-1);
const char nl = '\n';
const double eps = 1e-9;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define F first
#define S second

#define vt vector
#define pq priority_queue
#define mp make_pair
#define pb push_back

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define rep(i, k, n) for(int i = k; i < n; ++i)
#define repe(a, x) for(auto &a: x)
#define repr(i, n, k) for(int i = n; i >= k; --i)

template<class T> void read(T &x) {
	cin >> x;
}
void read(double &d) {
	string s;
	read(s);
	d = stod(s);
}
void read(long double &d) {
	string s;
	read(s);
	d = stold(s);
}
template<class H, class... T> void read(H &h, T&... t) {
	read(h);
	read(t...);
}
template<class T> void read(vt<T> &x) {
	repe(a, x) read(a);
}

void solve() {
	;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// read(t);
	while (t--) solve();
	return 0;
}