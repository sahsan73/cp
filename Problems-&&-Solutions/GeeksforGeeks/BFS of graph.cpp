/*
Problem Statement: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/


class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> answer;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            answer.push_back(u);
            
            for(int v: adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        return answer;
    }
};
