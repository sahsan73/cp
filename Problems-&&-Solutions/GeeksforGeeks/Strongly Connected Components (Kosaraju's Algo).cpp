/*
Problem Statement: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KOSARAJU'S ALGORITHM
*/
const int mxN = 5e3;

class Solution {
private:
    vector<int> adj2[mxN];  // reverse adjacency list
    bool vis[mxN];
    stack<int> st;
    
    void dfs1(int u, vector<vector<int>> &adj) {
        vis[u] = 1;
        for(int v: adj[u]) {
            if(!vis[v])
                dfs1(v, adj);
        }
        st.push(u);
    }
    
    void dfs2(int u) {
        vis[u] = 0;
        for(int v: adj2[u]) {
            if(vis[v])
                dfs2(v);
        }
    }
    
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj) {
        //code here
        for(int i=0; i<n; ++i) {
            if(!vis[i])
                dfs1(i, adj);
        }
        
        for(int i=0; i<n; ++i) {
            for(int j: adj[i])
                adj2[j].push_back(i);
        }
        int cnt = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(vis[u])
                dfs2(u), ++cnt;
        }
        return cnt;
    }
};
