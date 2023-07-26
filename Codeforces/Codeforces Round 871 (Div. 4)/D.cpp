#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, m;

bool dfs(int n) {
	if(n==m) return 1;
	if(n==0||n%3) return 0;
	return dfs(n/3)||dfs(2*n/3);
}

void solve() {
	cin >> n >> m;
	if(dfs(n))
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
