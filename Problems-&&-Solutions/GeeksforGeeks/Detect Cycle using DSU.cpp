/*
Problem Statement: https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
*/
struct DisjointSetUnion {
    int p[10000], s[10000];
    DisjointSetUnion(int n) {
        iota(p, p+n, 0);
        fill(s, s+n, 1);
    }
    
    int find(int u) {
        return u^p[u] ? p[u]=find(p[u]) : u;
    }
    
    bool join(int u, int v) {
        if((u=find(u)) == (v=find(v)))
            return 1;
        
        if(s[u] < s[v])
            swap(u, v);
        p[v] = u;
        s[u] += s[v];
        return 0;
    }
};

class Solution {
public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int n, vector<int>adj[]) {
	    // Code here
	    DisjointSetUnion dsu(n);
	    set<pair<int, int>> e;
	    for(int i=0; i<n; ++i) {
	        for(int j: adj[i]) {
	            if(!e.count({i, j}) && !e.count({j, i}) && dsu.join(i, j))
	                return 1;
	            e.insert({i, j});
	        }
	    }
	    return 0;
	}
};
