#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e2;
int n, m, q;
ll d[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(d, 0x3f, sizeof(d));
	cin >> n >> m >> q;
	for(int i=0; i<m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c, --a, --b;
		d[a][b]=min(d[a][b], c);
		d[b][a]=min(d[b][a], c);
	}
	
	// FLOYD-WARSHALL ALGORITHM
	for(int i=0; i<n; ++i)
		d[i][i]=0;
	for(int x=0; x<n; ++x) { // x-->intermediate node
		for(int u=0; u<n; ++u) {  // u-->src node
			for(int v=0; v<n; ++v) { // v-->dst node
				if(d[u][x]>=1e18||d[x][v]>=1e18)
					continue;
				d[u][v]=min(d[u][v], d[u][x]+d[x][v]);
			}
		}
	}

	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		cout << (d[a][b]>=1e18?-1:d[a][b]) << "\n";
	}


	return 0;
}
