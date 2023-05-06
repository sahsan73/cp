#include <bits/stdc++.h>
using namespace std;
 
const string s="codeforces";
string t;
 
void solve() {
	cin >> t;
	int cnt=0;
	for(int i=0; i<10; ++i) {
		if(t[i]!=s[i]) ++cnt;
	}
	cout << cnt << '\n';
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
