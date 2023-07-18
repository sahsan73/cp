/*
Problem Statement: https://atcoder.jp/contests/abc202/tasks/abc202_e

APPROACH: EULER TOUR
    - Suppose we have a graph/tree (adjacency list) rooted at vertex 1, draw on paper then it will be much easier to understand
            1: 2, 3
            2: 1, 4, 5, 7
            3: 1
            4: 2, 6
            5: 2
            6: 4
            7: 2

    - Now, if we perform a Euler tour on this graph (did not increase time when leaving a node)
            Timeline/Timer:    0    1    2    3    4    5    6    7
              Descend node:    1    2    4    6    5    7    3
                Leave node:                       6/4   5   7/2   3

    - If we have two nodes u and v, then v will be descendant of u if-and-only if, "ds[u] <= ds[v] && de[v] < ds[u]"
         - ds ==> descend start (enter)
         - de ==> descend end (leave)

    - But, we have another constraint that the no. of edges from root to v, in other words - depth of v. We will map the node's
      descend start (ds) time with node's depth, and then will apply the above condition to count no. of descendants at query time.

COMPLEXITY:
    - TC = O(n+m)
    - SC = (n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define sz(x) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, q, d1[mxN], ds[mxN], de[mxN], dt; // ds ==> node enter time, de ==> node leave time, dt ==> timer
vt<int> adj[mxN], dp[mxN]; // adj ==> adjacency list, dp ==> mapping depth and ds time

// Euler tour
void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	d1[u]=p==-1?0:d1[p]+1;
	dp[d1[u]].pb(ds[u]);

	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
	}
	de[u]=dt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1, p; i<n; ++i) {
		cin >> p, --p;
		adj[i].pb(p);
		adj[p].pb(i);
	}

	dfs();
	
	cin >> q;
	while(q--) {
		int u, d;
		cin >> u >> d, --u;
        // dp[d1] = {ds1, ds2, ds3, ....}, they are sorted so we can use inbuilt function to count required nodes
		int cnt=upper_bound(all(dp[d]), de[u]-1)-lower_bound(all(dp[d]), ds[u]);
		cout << cnt << "\n";
	}

	return 0;
}
