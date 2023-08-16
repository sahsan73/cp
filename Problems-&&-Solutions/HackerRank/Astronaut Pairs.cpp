/*
Problem Statement: https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs/problem
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2.5e4;
int n, p, vis[mxN], cnt;
vector<int> adj[mxN];

void dfs(int u) {
	vis[u]=1;
	++cnt;
	for(int v: adj[u]) {
		if(!vis[v])
			dfs(v);
	}
}

int main() {
	cin >> n >> p;
	for(int i=0, a, b; i<p; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> co; // component size
	for(int i=0; i<n; ++i) {
		if(!vis[i]) {
			dfs(i);
			co.push_back(cnt);
			cnt=0;
		}
	}
	int a=0;
	for(int i=0; i<co.size(); ++i) {
		for(int j=i+1; j<co.size(); ++j)
			a+=co[i]*co[j];
	}
	cout << a;

	return 0;
}
