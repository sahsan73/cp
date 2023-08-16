/*
Problem Statement: https://cses.fi/problemset/task/1652
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, q, ps[mxN+1][mxN+1];
string s[mxN+1];

int main() {
	cin >> n >> q;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		for(int j=0; j<n; ++j)
			ps[i+1][j+1]=ps[i+1][j]+ps[i][j+1]-ps[i][j]+(s[i][j]=='*');
	}

	while(q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << (ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]) << "\n";
	}

	return 0;
}
