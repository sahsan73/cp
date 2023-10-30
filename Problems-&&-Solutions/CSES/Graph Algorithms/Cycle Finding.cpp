/*
Problem Statement: https://cses.fi/problemset/task/1197/

Some Test Cases:
#1 -->  4 5 (given sample test)
        1 2 1
        2 4 1
        3 1 1
        4 1 -3
        4 3 -2


#2 -->  4 5
        1 2 1
        2 4 1
        3 1 1
        4 1 1
        4 3 -4
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2.5e3;
int n, m, p[mxN], vis[mxN];
vector<ar<int, 3>> e;
ll d[mxN];

void solve() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		e.push_back({a, b, c});
	}
	memset(d, 0x3f, sizeof(d));
	memset(p, -1, sizeof(p));
	int x;
	d[0]=0;
	for(int i=0; i<n; ++i) {
		x=-1;
		for(int j=0; j<m; ++j)
			if(d[e[j][0]]+e[j][2]<d[e[j][1]]) {
				d[e[j][1]]=d[e[j][0]]+e[j][2];
				p[e[j][1]]=e[j][0];
				x=e[j][1];
			}
	}
	//cout << "x: " << x+1 << "\n";
	//for(int i=0; i<n; ++i)
		//cout << "(" << i+1 << ", " << p[i]+1 << ")" << "\n";
	if(~x) {
		// it is NOT necessary that the vextex x would belong to the negative cycle
		// so we need to make sure the we are in the cycle ---> draw the above test
		// cases on paper and see what's actually happening!
		while(!vis[x]) {
			vis[x]=1;
			x=p[x];
		}
		vector<int> cyc;
		while(cyc.empty()||x^cyc[0]) {
			cyc.push_back(x);
			x=p[x];
		}
		cyc.push_back(x);
		reverse(cyc.begin(), cyc.end());
		cout << "YES\n";
		for(int y: cyc)
			cout << y+1 << " ";
	} else
		cout << "NO";
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
