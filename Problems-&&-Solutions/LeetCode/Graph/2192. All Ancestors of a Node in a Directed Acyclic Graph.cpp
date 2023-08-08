/*
Problem Statement: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: TOPO SORT (KAHN'S ALGORITHM)
*/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<int> adj[1000], indeg(n, 0), st;
        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            ++indeg[v];
        }

        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v: adj[u]) {
                --indeg[v];
                if(indeg[v] == 0)
                    q.push(v);
            }
            st.push_back(u);
        }

        vector<set<int>> anc(n);
        for(int u: st) {
            for(int v: adj[u]) {
                for(int a: anc[u])
                    anc[v].insert(a);
                anc[v].insert(u);
            }
        }
        vector<vector<int>> answer;
        for(int i=0; i<n; ++i)
            answer.push_back({anc[i].begin(), anc[i].end()});
        return answer;
    }
};
