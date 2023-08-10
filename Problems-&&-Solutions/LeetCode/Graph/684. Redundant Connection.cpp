/*
Problem Statement: https://leetcode.com/problems/redundant-connection/description/
*/

struct DisjointSetUnion {
    int p[1000], s[1000];
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
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = (int)edges.size();
        DisjointSetUnion dsu(n);
        vector<int> a;
        for(auto &e: edges) {
            if(dsu.join(e[0]-1, e[1]-1))
                a = e;
        }
        return a;
    }
};
