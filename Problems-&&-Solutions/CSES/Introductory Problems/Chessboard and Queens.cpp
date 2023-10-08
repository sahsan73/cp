/*
Problem Statement: https://cses.fi/problemset/task/1624
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

string s[8];

bool e(int i, int j) {
	if(s[i][j]=='*')
		return 0;
	// check column
	for(int r=i; ~r; --r)
		if(s[r][j]=='Q')
			return 0;
	// check row
	for(int c=j; ~c; --c)
		if(s[i][c]=='Q')
			return 0;
	// upper-left diagonal
	for(int r=i, c=j; ~r&&~c; --r, --c)
		if(s[r][c]=='Q')
			return 0;
	// upper-right diagonal
	for(int r=i, c=j; ~r&&c<8; --r, ++c)
		if(s[r][c]=='Q')
			return 0;
	return 1;
}

int dfs(int i) {
	if(i==8)
		return 1;
	int a=0;
	for(int j=0; j<8; ++j) {
		if(e(i, j)) {
			s[i][j]='Q';
			a+=dfs(i+1);
			s[i][j]='.';
		}
	}
	return a;
}

void solve() {
	for(int i=0; i<8; ++i)
		cin >> s[i];
	cout << dfs(0);
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
