#include <bits/stdc++.h>
using namespace std;
 
const int INF=1e9+5;
int n;
 
void solve() {
	cin >> n;
	unordered_map<string,int> mp;
	mp["00"]=mp["01"]=mp["10"]=mp["11"]=INF;
	for(int i=0; i<n; ++i) {
		int m; string s;
		cin >> m >> s;
		mp[s]=min(mp[s], m);
	}
 
	int r1=mp["11"];
	int r2=((mp["10"]!=INF)&&mp["01"]!=INF)?mp["10"]+mp["01"]:INF;
	cout << ((min(r1,r2)==INF)?-1:min(r1,r2)) << '\n';
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
