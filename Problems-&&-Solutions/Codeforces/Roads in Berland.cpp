/*
Problem Statement: https://codeforces.com/contest/25/problem/C

Approach: Floyed-Warshall Algorithm for APSP
    - We are given a 2D matrix d, where d[u][v] is the distance of shortest path b/w city u and city v.
    - Now if we connect city a and city b, and new distance b/w city u and city v becomes d1[u][v], we have three possible ways...
        1. d1[u][v] remains unchanges, i.e., d1[u][v] = d[u][v]
        2. d1[u][v] is shorter if we use the new road ab. This means that the new path from u to v must include the road ab. If we
           connect the vertices together, then our new distance will be d1[u][v] = d[u][a] + length(ab) + d[b][v].
        3. We may have to use the road ba (ba may not be the same as road ab). In this case, we have d1[u][v] = d[u][b] + length(ab) + d[a][v].

COMPLEXITY:
    - TC = O(k*n^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=3e2;
int n, d[mxN][mxN], k;
ll ans[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			cin >> d[i][j];
	}

	cin >> k;
	for(int i=0, a, b, c; i<k; ++i) {
		cin >> a >> b >> c, --a, --b;
		for(int u=0; u<n; ++u) {
			for(int v=0; v<n; ++v)
				d[u][v]=min({d[u][v], d[u][a]+c+d[b][v], d[u][b]+c+d[a][v]});
		}

		ll s=0;
		for(int u=0; u<n; ++u) {
			for(int v=u+1; v<n; ++v)
				s+=d[u][v];
		}
		ans[i]=s;
	}
	for(int i=0; i<k; ++i)
		cout << ans[i] << " ";

	return 0;
}
