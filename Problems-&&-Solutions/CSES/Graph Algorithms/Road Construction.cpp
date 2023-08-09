/*
Problem Statement: https://cses.fi/problemset/task/1676
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DISJOINT SET UNION
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, mxM=2e5;
int n, m, p[mxN], s[mxN];
ar<ll, 2> e[mxM];

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
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> e[i][0] >> e[i][1];
		--e[i][0], --e[i][1];
	}

	iota(p, p+n, 0);
	fill(s, s+n, 1);
	int a1=n, a2=0;
	for(int i=0; i<m; ++i) {
		if(join(e[i][0], e[i][1]))
			--a1, a2=max({a2, s[find(e[i][0])], s[find(e[i][1])]});
		cout << a1 << " " << a2 << "\n";
	}

	return 0;
}

