/*
Problem Statement: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: PRIM'S ALGORITHM FOR MST
*/
class Solution {
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        // code here
        bool vis[1000] = {};
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        pq.push({0, 0});
        
        int answer = 0;
        while(!pq.empty()) {
            array<int, 2> u = pq.top();  // u[0] --> wt, u[1] --> node
            pq.pop();
            if(vis[u[1]])
                continue;
            
            for(auto &v: adj[u[1]]) { // v[0] --> node, v[1] --> wt
                if(!vis[v[0]]) {
                    pq.push({v[1], v[0]});
                }
            }
            
            answer += u[0];
            vis[u[1]] = 1;
        }
        return answer;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KRUSKAL'S ALGORITHM FOR MST
*/
