/*
Problem Statement: https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
int n, m, p[1000][1000];
string s[1000], dir="URDL";
ar<int, 2> a, b;

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		for(int j=0; j<m; ++j) {
			if(s[i][j]=='A')
				a={i, j}, s[i][j]='#';
			if(s[i][j]=='B')
				b={i, j}, s[i][j]='.';
		}
	}

	auto e=[&](int i, int j) {
		return (i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.');
	};
	
	memset(p, -1, sizeof(p));
	queue<ar<int, 2>> q;
	q.push(a);
	while(!q.empty()) {
		ar<int, 2> u=q.front();
		q.pop();
		if(u==b)
			break;
		for(int k=0; k<4; ++k) {
			int ni=u[0]+d4i[k];
			int nj=u[1]+d4j[k];
			if(e(ni, nj)) {
				q.push({ni, nj});
				s[ni][nj]='#';
				p[ni][nj]=k;
			}
		}
	}
	if(p[b[0]][b[1]]==-1) {
		cout << "NO";
		return;
	}
	string res;
	while(b[0]^a[0]||b[1]^a[1]) {
		int k=p[b[0]][b[1]];
		res.push_back(dir[k]);
		b[0]-=d4i[k];
		b[1]-=d4j[k];
		/*
		 * Another way to get the parent
		 * k^=2;  <-- This will 1 to 3 and 0 to 2
   		 * so it is same if we add upward direction instead of subtract downward direction
		 * b[0]+=d4i[k]
		 * b[1]+=d4j[k]
		 */
	}
	reverse(res.begin(), res.end());
	cout << "YES\n" << res.size() << "\n" << res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
