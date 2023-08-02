/*
Problem Statement: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0
*/


class Solution {
private:
    vector<int> answer;
    bool vis[10000];

    void dfs(int u, vector<int> adj[]) {
        vis[u] = 1;
        answer.push_back(u);
        for(int v: adj[u]) {
            if(!vis[v])
                dfs(v, adj);
        }
    }
    
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        memset(vis, 0, sizeof(vis));
        answer.clear();
        
        for(int i=0; i<n; ++i) {
            if(!vis[i])
                dfs(i, adj);
        }
        return answer;
    }
};
