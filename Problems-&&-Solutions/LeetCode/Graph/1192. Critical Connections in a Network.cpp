/*
APPROACH: Tarjan's Algorithm for finding bridges in an Undirected Graph

COMPLEXITY:
    - TC = O(n+m)
*/
const int mxN = 1e5;

class Solution {
private:
    int n, ds[mxN], dl[mxN], dt;
    vector<int> adj[mxN];
    vector<vector<int>> answer;
    
    void init(int n, vector<vector<int>> &edges) {
        this->n = n;
        for(int i=0; i<n; ++i) {
            ds[i] = dl[i] = 0;
            adj[i].clear();
        }
        dt = 0;
        answer.clear();

        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int u, int p, vector<bool> &vis) {
        ds[u] = dl[u] = dt++;
        vis[u] = 1;
        for(int v: adj[u]) {
            if(v == p) continue;

            if(!vis[v]) {
                dfs(v, u, vis);
                dl[u] = min(dl[u], dl[v]);
            } else {
                // we have a backedge
                dl[u] = min(dl[u], ds[v]);
            }

            // check for bridge
            if(dl[v] > ds[u]) {
                answer.push_back({u, v});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        init(n, connections);
        vector<bool> vis(n, false);
        dfs(0, -1, vis);
        return answer;
    }
};
