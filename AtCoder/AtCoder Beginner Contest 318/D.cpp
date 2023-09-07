/*
UPSOLVE

APPROACH: DYNAMIC PROGRAMMING
    - Since mxN is 16, we can use bits to keep track of visited nodes
    - Use DP of cache the state-->set of bits represent visited/unvisited number
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
DURING CONTEST
    - Brute force approach
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, vis[16];
ll d[16][16];

ll dfs() {
	if(count(vis, vis+n, 1)==n)
		return 0;
	// find an unvisited node
	int u=find(vis, vis+n, 0)-vis;
	vis[u]=1;
	ll r=0LL;
	for(int v=u+1; v<n; ++v) {
		if(!vis[v]) {
			vis[v]=1;
			r=max(r, d[u][v]+dfs());
			vis[v]=0;
		}
	}
	vis[u]=0;
	return r;
}

int main() {
	cin >> n;
	for(int i=0; i<n-1; ++i) {
		for(int j=i+1; j<n; ++j) {
			int w;
			cin >> w;
			d[i][j]=d[j][i]=w;
		}
	}

	ll a=0LL;
	if(n&1) {
		// in case of odd no. of nodes, one of the nodes
		// will be ignored
		for(int i=0; i<n; ++i) {
			vis[i]=1; // ignore node 'i'
			a=max(a, dfs());
			vis[i]=0;
		}
	} else
		a=dfs();
	cout << a;

	return 0;
}
