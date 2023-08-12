/*
Problem Statement: https://cses.fi/problemset/task/1667/
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, p[mxN], vis[mxN];
vector<int> adj[mxN];

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	iota(p, p+n, 0);
	queue<int> q;
	q.push(0);
	vis[0]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v: adj[u]) {
			if(!vis[v]) {
				q.push(v);
				p[v]=u;
				vis[v]=1;
			}
		}
	}
	
	vector<int> a;
	int i=n-1;
	for(; i^p[i]; i=p[i])
		a.push_back(i+1);
	;
	if(i) {
		cout << "IMPOSSIBLE";
	} else {
		a.push_back(1);
		reverse(a.begin(), a.end());
		cout << a.size() << "\n";
		for(int j=0; j<a.size(); ++j)
			cout << a[j] << " ";
	}

	return 0;
}
