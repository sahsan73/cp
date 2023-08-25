/*
Problem Statement: https://leetcode.com/problems/redundant-connection-ii/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DISJOINT SET UNION
    - Yes, we CANNOT use DSU to detect cycle in directed graph.
    - But, we can apply to detect a cycle in the graph, if we are DEFINITELY sure that directed graph contains a cycle!!
*/
const int mxN = 1000;

struct DisjointSetUnion {
    int p[mxN+1], r[mxN+1];

    DisjointSetUnion(int n) {
        for(int i=0; i<=n; ++i) {
            // since we are using 1-based index, don't use p[i] = i
            // because find_set function will then return 0 as a parent of 1
            p[i] = -1;
            r[i] = 0;
        }
    }

    int find_set(int u) {
        if(p[u] == -1) return u;
        return p[u] = find_set(p[u]);
    }

    // returns true is there exist a cycle in the graph
    bool union_sets(int u, int v) {
        u = find_set(u), v = find_set(v);
        if(u == v) return true;

        if(r[u] < r[v])
            swap(u, v);
        p[v] = u;
        if(r[u] == r[v])
            ++r[u];
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = (int)edges.size();
        int p[mxN+1]{};

        // Case-I: inspecting only two parent situation
        // in this case later edge will be our answer as mentioned in the problem
        vector<int> e1, e2;
        for(auto &e: edges) {
            int u = e[0], v = e[1]; // u is a parent of v
            if(p[v] != 0) {
                e1 = {p[v], v};
                e2 = {u, v};
                break;
            }
            p[v] = u;
        }

        // Case-II: Now if there only (no two parent of a node) a cycle in graph, we didn't have any edges
        // as e1 or e2, so we simply check which edge causing the cycle.
        // Case-III: If there is a cycle in the graph as well as a node with two parent, then one
        // of the edges either e1 or e2 must be the part of that cycle.
        // Since we assumed that e2 will be our answer if two parent node exist, we will try check if a cycle
        // exist without the edge e2. If NO, then e2 is indeed our answer i.e., the edge causing cycle as well
        // as two parent, otherwise e1.
        DisjointSetUnion dsu(n);
        for(auto &e: edges) {
            if(e == e2) continue;

            if(dsu.union_sets(e[0], e[1])) {
                // don't simply return e, take the example --> [[2,1],[3,1],[4,2],[1,4]] : Case-III
                // don't simply return e1, take the example --> [[1,2],[2,3],[3,1]] : Case-II
                // the point is, we don't know the order of edges so if current edge e causes cycle
                // that NOT necessarily be the e1.
                return !e1.empty() ? e1 : e;
            }
        }
        return e2;
    }
};
