#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};

const int mxN=1e3;
int m, n, a[mxN][mxN];
bool vis[mxN][mxN];

int dfs(int r, int c) {
	int res=a[r][c];
	vis[r][c]=1;
	auto inbound=[&](int i, int j) {
		return (i>=0&&i<m&&j>=0&&j<n);
	};

	for(int k=0; k<4; ++k) {
		int nr=r+d4i[k];
		int nc=c+d4j[k];
		if(inbound(nr, nc)&&!vis[nr][nc]&&a[nr][nc]>0)
			res+=dfs(nr, nc);
	}
	return res;
}

void solve() {
	cin >> m >> n;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j)
			cin >> a[i][j];
	}

	memset(vis, 0, sizeof(vis));
	int ans=0;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			if(!vis[i][j]&&a[i][j]>0)
				ans=max(ans, dfs(i, j));
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) solve();
	return 0;
}
