#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, m;

void solve() {
	cin >> n >> m;
	vt<int> deg(n+1, 0); // deg[u]=no. of direct connections a node has with other nodes(in undirected graph)
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		++deg[u], ++deg[v];
	}
	
	// deg[u]:cnt, if cnt==1 then u==central vertex and deg[u]==x
	// 			   if cnt==x then deg[u]==y+1
	// 			   if cnt==xy then deg[u]==1
	unordered_map<int,int> mp;
	for(int i=1; i<=n; ++i) ++mp[deg[i]];
   	
	vt<int> cnts; // {x, 1, xy}
	for(auto &p: mp) cnts.pb(p.second);
	sort(all(cnts)); // {1, x, xy}
	if(sz(cnts)==3) {
		cout << cnts[1] << ' ' << cnts[2]/cnts[1] << '\n';
	} else {
		// edge cases if x==y+1, then cnts=={x+1, xy}
		cout << cnts[0]-1 << ' ' << cnts[1]/(cnts[0]-1) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
