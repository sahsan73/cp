/*
Problem Statement: https://atcoder.jp/contests/arc076/tasks/arc076_b
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KRUSKAL'S ALGORITHM FOR MST
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, p[mxN], s[mxN];
vector<ar<int, 3>> e;

int find(int u) {
	return u^p[u]?p[u]=find(p[u]):u;
}

bool join(int u, int v) {
	if((u=find(u))==(v=find(v)))
		return 0;
	if(s[u]<s[v])
		swap(u, v);
	p[v]=u;
	s[u]+=s[v];
	return 1;
}

int main() {
	cin >> n;
	vector<ar<int, 3>> c; //{x, y, nodeID}
	for(int i=0, x, y; i<n; ++i) {
		cin >> x >> y;
		c.push_back({x, y, i});
	}
	//for(int i=0; i<n; ++i) {
		//for(int j=i+1; j<n; ++j) {
			//int d=min(abs(c[i][0]-c[j][0]), abs(c[i][1]-c[j][1]));
			//e.push_back({i, j, d});
		//}
	//}

	sort(c.begin(), c.end()); // sort by x-coordinates
	for(int i=1; i<n; ++i)
		e.push_back({c[i][2], c[i-1][2], c[i][0]-c[i-1][0]});
	sort(c.begin(), c.end(), [](auto &c1, auto &c2){ // sort by y-coordinates
		return c1[1]<c2[1];
	});
	for(int i=1; i<n; ++i)
		e.push_back({c[i][2], c[i-1][2], c[i][1]-c[i-1][1]});

	sort(e.begin(), e.end(), [](auto &e1, auto &e2){
		return e1[2]<e2[2];
	});
	iota(p, p+n, 0);
	fill(s, s+n, 1);
	ll a=0;
	for(int i=0; i<e.size(); ++i) {
		if(join(e[i][0], e[i][1]))
			a+=(ll)e[i][2];
	}
	cout << a;

	return 0;
}
