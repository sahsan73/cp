/*
Problem Statement: https://cses.fi/problemset/task/1667/
*/
#include <bits/stdc++.h>
using namespace std;
 
const int mxN=1e5;
int n, m, p[mxN];
vector<int> adj[mxN];
 
int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	memset(p, -1, sizeof(p));
	queue<int> qu;
	qu.push(0);
	p[0]=0;
	while(!qu.empty()) {
		int u=qu.front();
		qu.pop();
		for(int v: adj[u]) {
			if(p[v]<0) {
				qu.push(v);
				p[v]=u;
			}
		}
	}
	if(p[n-1]<0)
		cout << "IMPOSSIBLE";
	else {
		vector<int> a;
		for(int i=n-1; i^p[i]; i=p[i])
			a.push_back(i);
		a.push_back(0);
		reverse(a.begin(), a.end());
		cout << a.size() << "\n";
		for(int i=0; i<a.size(); ++i)
			cout << a[i]+1 << " ";
	}
 
	return 0;
}
