/*
Problem Statement: https://leetcode.com/problems/making-a-large-island/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DISJOINT SET UNION (DSU)
*/
struct DisjointSetUnion {
    int p[250000], s[250000];
    DisjointSetUnion(int n) {
        iota(p, p+n, 0);
        fill(s, s+n, 1);
    }

    int find(int u) {
        return u^p[u] ? p[u]=find(p[u]) : u;
    }

    void join(int u, int v) {
        if((u=find(u)) == (v=find(v)))
            return;
        if(s[u] < s[v])
            swap(u, v);
        p[v] = u;
        s[u] += s[v];
    }
};

class Solution {
private:
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = (int)grid.size();
        auto inbound = [&](int r, int c) {
            return (r>=0 && r<n && c>=0 && c<n);
        };

        DisjointSetUnion dsu(n*n);
        int singleIsland = 1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 0) {
                    singleIsland = 0;
                    continue;
                }

                int u = i * n + j;
                for(int k=0; k<4; ++k) {
                    int ni = i + d4i[k];
                    int nj = j + d4j[k];
                    if(inbound(ni, nj) && grid[ni][nj]) {
                        int v = ni * n + nj;
                        dsu.join(u, v);
                    }
                }
            }
        }
        if(singleIsland) return n*n;

        int answer = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1) continue;

                unordered_set<int> st;
                for(int k=0; k<4; ++k) {
                    int ni = i + d4i[k];
                    int nj = j + d4j[k];
                    if(inbound(ni, nj) && grid[ni][nj]) {
                        int v = ni * n + nj;
                        st.insert(dsu.find(v));
                    }
                }

                int s = 0;
                for(int p: st)
                    s += dsu.s[p];
                answer = max(answer, s+1);
            }
        }
        return answer;
    }
};
