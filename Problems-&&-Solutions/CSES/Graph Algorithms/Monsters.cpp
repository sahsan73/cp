/*
This is an extension of the CSES problem Labyrinth!
    - problem: https://cses.fi/problemset/task/1193

Problem Statement: https://cses.fi/problemset/task/1194
    - The idea is very simple, calculate the minimum distances from the person and monsters to each exit points.
    - If at any exit point, minimum distance from the person is less than any monster's minimum distance, then this
      is the exit person must follow!
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
int n, m, si, sj, d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];
string s[mxN], dir="URDL";
bool vis[mxN][mxN];

int e(int i, int j) {
	return (i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.'&&!vis[i][j]);
}

void bfs(vector<ar<int, 2>> v1, int d[mxN][mxN], int p[mxN][mxN]) {
	memset(vis, 0, sizeof(vis));
	memset(d, 0x3f, sizeof(d1));
	queue<ar<int, 2>> qu;
	for(ar<int, 2> a: v1) {
		qu.push(a);
		vis[a[0]][a[1]]=1;
		d[a[0]][a[1]]=1;
	}
	while(!qu.empty()) {
		ar<int, 2> u=qu.front();
		qu.pop();
		for(int k=0; k<4; ++k) {
			int ni=u[0]+d4i[k];
			int nj=u[1]+d4j[k];
			if(!e(ni, nj))
				continue;
			qu.push({ni, nj});
			vis[ni][nj]=1;
			d[ni][nj]=d[u[0]][u[1]]+1;
			p[ni][nj]=k;
		}
	}
}

void solve() {
	cin >> n >> m;
	vector<ar<int, 2>> v2;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		for(int j=0; j<m; ++j) {
			if(s[i][j]=='A')
				si=i, sj=j, s[i][j]='.';
			if(s[i][j]=='M')
				v2.push_back({i, j}), s[i][j]='.';
		}
	}

	bfs({{si, sj}}, d1, p1);
	bfs(v2, d2, p2);

	// check for the exit point of the person, there'll be an
	// exit if and only if minimum distance from the exit to the
	// person must be less than the minimum distance from any monsters.
	int ti=-1, tj=-1;
	for(int i=0; i<n; ++i) {
		// left boundary --> (i, 0)
		if(d1[i][0]<d2[i][0])
			ti=i, tj=0;
		// right boundar --> (i, m-1)
		if(d1[i][m-1]<d2[i][m-1])
			ti=i, tj=m-1;
	}
	for(int j=0; j<m; ++j) {
		// upper boundary --> (0, j)
		if(d1[0][j]<d2[0][j])
			ti=0, tj=j;
		// lower boundary --> (n-1, j)
		if(d1[n-1][j]<d2[n-1][j])
			ti=n-1, tj=j;
	}
	if(~ti) {
		cout << "YES" << "\n";
		string res;
		while(ti^si||tj^sj) {
			int k=p1[ti][tj];
			res+=dir[k];
			ti-=d4i[k];
			tj-=d4j[k];
		}
		reverse(res.begin(), res.end());
		cout << res.size() << "\n" << res;
	} else
		cout << "NO";
}

int main() {
	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
