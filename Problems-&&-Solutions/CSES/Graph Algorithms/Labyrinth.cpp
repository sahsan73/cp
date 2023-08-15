/*
Problem Statement: https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e3, d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const char dir[4]={'U', 'R', 'D', 'L'};
int n, m, si, sj, ti, tj, d[mxN][mxN];
string s[mxN], p[mxN];

bool e(int i, int j) {
	return (i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.');
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		for(int j=0; j<m; ++j) {
			if(s[i][j]=='A')
				si=i, sj=j, s[i][j]='#';
			if(s[i][j]=='B')
				ti=i, tj=j, s[i][j]='.';
		}
		p[i]=string(m, 0);
	}

	queue<ar<int, 2>> qu;
	qu.push({si, sj});
	while(!qu.empty()) {
		ar<int, 2> u=qu.front();
		qu.pop();
		for(int k=0; k<4; ++k) {
			int ni=u[0]+d4i[k];
			int nj=u[1]+d4j[k];
			if(e(ni, nj)) {
				qu.push({ni, nj});
				d[ni][nj]=k;
				p[ni][nj]=dir[k];
				s[ni][nj]='#';
			}
		}
	}

	if(p[ti][tj]) {
		cout << "YES" << "\n";
		string t;
		while(ti^si||tj^sj) {
			t+=p[ti][tj];
			int k=d[ti][tj];
			ti=ti-d4i[k];
			tj=tj-d4j[k];
			/*
			 * Another way to get the parent
			 * int k=p[ti][tj]^2
			 * ti+=d4i[k]
			 * tj+=d4j[k]
			 */
		}
		reverse(t.begin(), t.end());
		cout << t.size() << "\n" << t;
	} else
		cout << "NO";

	return 0;
}
