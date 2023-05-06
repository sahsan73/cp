#include <bits/stdc++.h>
using namespace std;
 
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
 
const int INF=1e9+5;
int m, n;
 
bool dfs(int n) {
	if(n==m) return 1;
	if(n%3) return 0;
 
	return (dfs(n/3)|dfs((2*n)/3));
}
 
void solve() {
	cin >> n >> m;
	if(dfs(n)) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
