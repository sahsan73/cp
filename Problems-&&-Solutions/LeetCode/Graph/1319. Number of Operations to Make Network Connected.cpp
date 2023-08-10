/*
Problem Statement: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
*/
struct DisjointSetUnion {
    int p[100000], s[100000];
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
    int makeConnected(int n, vector<vector<int>> &connections) {
        int cnt1=0; // cnt1 --> no. of extra cables
        DisjointSetUnion dsu(n);
        for(auto &e: connections) {
            if(dsu.join(e[0], e[1]))
                ++cnt1;
        }

        int cnt2 = (int)connections.size() - cnt1 + 1; // cnt2-->total no. of connected computers
        // so total no. of disconnected computers = n - cnt2
        if(cnt1 < n-cnt2)
            return -1;
        return n-cnt2;
    }
};
