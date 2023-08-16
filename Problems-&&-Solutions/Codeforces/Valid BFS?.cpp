/*
Problem Statement: https://codeforces.com/problemset/problem/1037/D

APPROACH:
    - We can store the neighbors of the nodes in their adjacency lists. After that, we can sort the adjacency lists of all the nodes in
      the order in which they are present in the input BFS Sequence.

    - Now we can do the standard BFS traversal starting from node 1and check if this BFS traversal is same as the input BFS
      Sequence. If its not, the answer will be "No".
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, vis[mxN], bt[mxN]; // bt-->bfs traversal
vector<int> adj[mxN];

int main() {
	cin >> n;
	for(int i=1, x, y; i<n; ++i) {
		cin >> x >> y, --x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	unordered_map<int, int> mp;
	for(int i=0; i<n; ++i)
		cin >> bt[i], --bt[i], mp[bt[i]]=i;

	for(int i=0; i<n; ++i) {
		sort(adj[i].begin(), adj[i].end(), [&](int x, int y){
			return mp[x]<mp[y];
		});
	}

	vector<int> a;
	queue<int> qu;
	qu.push(0);
	vis[0]=1;
	while(!qu.empty()) {
		int u=qu.front();
		qu.pop();
		for(int v: adj[u]) {
			if(!vis[v]) {
				qu.push(v);
				vis[v]=1;
			}
		}
		a.push_back(u);
	}
	for(int i=0; i<n; ++i) {
		if(a[i]^bt[i]) {
			cout << "No";
			exit(0);
		}
	}
	cout << "Yes";

	return 0;
}
