#include <bits/stdc++.h>
using namespace std;
 
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
 
const int INF=1e9+5;
int m, n;
 
int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis) {
	if(r<0||c<0||r>=m||c>=n||vis[r][c]||grid[r][c]==0) return 0;
	
	int res=grid[r][c];
	vis[r][c]=1;
	for(int k=0; k<4; ++k) {
		res+=dfs(r+d4i[k], c+d4j[k], grid, vis);
	}
	return res;
}
 
void solve() {
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n));
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> grid[i][j];
		}
	}
 
	vector<vector<int>> vis(m, vector<int>(n, 0));
	int ans=0;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			if(grid[i][j]) {
				int res=dfs(i,j,grid, vis);
				ans=max(ans, res);
			}
		}
	}
	cout << ans << '\n';
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
