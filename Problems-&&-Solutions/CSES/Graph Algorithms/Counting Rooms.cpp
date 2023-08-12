/*
Problem Statement: https://cses.fi/problemset/task/1192/
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
int m, n, vis[mxN][mxN];
string s[mxN];

bool inbound(int r, int c) {
	return (r>=0&&r<n&&c>=0&&c<m);
}

void dfs(int r, int c) {
	vis[r][c]=1;
	for(int k=0; k<4; ++k) {
		int nr=r+d4i[k];
		int nc=c+d4j[k];
		if(inbound(nr, nc)&&s[nr][nc]=='.'&&!vis[nr][nc])
			dfs(nr, nc);
	}
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> s[i];
	
	int cnt=0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(!vis[i][j]&&s[i][j]=='.') {
				dfs(i, j);
				++cnt;
			}
		}
	}
	cout << cnt;

	return 0;
}
