/*
Problem Statement: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DFS
*/
class Solution {
private:
    bool vis[100000];
    
    bool dfs(int u, vector<int> adj[], int p=-1) {
        vis[u] = 1;
        for(int v: adj[u]) {
            if(!vis[v]) {
                if(dfs(v, adj, u))
                    return true;
            } else if(v != p) {
                return true;
            }
        }
        return false;
    }
    
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i) {
            if(!vis[i] && dfs(i, adj))
                return 1;
        }
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BFS
*/
class Solution {
public:
    bool vis[100000];
    #define ar array
    
    bool bfs(int u, vector<int> adj[]) {
        queue<ar<int, 2>> q;
        q.push({u, -1});
        vis[u] = 1;
        while(!q.empty()) {
            int u = q.front()[0], p = q.front()[1];
            q.pop();
            for(int v: adj[u]) {
                if(!vis[v]) {
                    q.push({v, u});
                    vis[v] = 1;
                } else if(v != p) {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i) {
            if(!vis[i] && bfs(i, adj))
                return true;
        }
        return false;
    }
};
