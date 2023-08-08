/*
Problem Statement: https://practice.geeksforgeeks.org/problems/topological-sort/1
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DFS
*/
class Solution {
private:
    bool vis[10000];
    
    void dfs(int u, vector<int> adj[], vector<int> &st) {
        vis[u] = 1;
        for(int v: adj[u]) {
            if(!vis[v])
                dfs(v, adj, st);
        }
        st.push_back(u);
    }
    
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) {
        // code here
        memset(vis, 0, sizeof(vis));
        
        vector<int> st;
        for(int i=0; i<n; ++i) {
            if(!vis[i])
                dfs(i, adj, st);
        }
        reverse(st.begin(), st.end());
        return st;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BFS (KAHN'S ALGORITHM)
*/
class Solution {
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) {
        // code here
        vector<int> indeg(n, 0), st;
        for(int i=0; i<n; ++i) {
            for(int j: adj[i])
                ++indeg[j];
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
        return st;
	}
};
