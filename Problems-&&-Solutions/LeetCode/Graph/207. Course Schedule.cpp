/*
Problem Statement: https://leetcode.com/problems/course-schedule/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BFS (KAHN'S ALGORITHM)
    - Topological Sort
*/
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[2000], indeg(n, 0), st;
        for(auto &e: p) {
            adj[e[1]].push_back(e[0]);
            ++indeg[e[0]];
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
        return st.size()==n;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DFS
    - Detect cycle in the graph, if there is one, there is NO way we can complete those courses.
*/
class Solution {
private:
    bool vis[2000], vis2[2000];

    bool dfs(int u, vector<int> adj[2000]) {
        vis[u] = vis2[u] = 1;
        for(int v: adj[u]) {
            if(!vis[v] && dfs(v, adj)) {
                return true;
            } else if(vis2[v]) {
                return true;
            }
        }
        vis2[u] = 0;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>> &p) {
        vector<int> adj[2000];
        for(auto &e: p) {
            int u = e[1], v = e[0];
            adj[u].push_back(v);
        }

        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis2));
        for(int i=0; i<n; ++i) {
            if(dfs(i, adj))
                return false;
        }
        return true;
    }
};
