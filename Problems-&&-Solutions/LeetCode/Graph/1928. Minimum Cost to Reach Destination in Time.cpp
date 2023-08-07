/*
Problem Statement: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DIJKSTRA'S ALGORITHM
    - We CAN'T just keep track of minimum cost since it may lead us to exceed maxTime. So we will prune
      those edges which lead us to exceed maxTime
    
    - Suppose we are at node u ($10, 5) and it has two adjacent nodes v1 ($13, 10), v2 ($17, 8). We see that
      currently total cost to go to v2 is more than v1. It is possible that later, the path via u-->v2 will lead
      us to optimal cost within maxTime.
*/
const int mxN = 1e3;
#define ar array

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &f) {
        int n = (int)f.size();
        vector<ar<int, 2>> adj[mxN];
        for(auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> c(n, 1e9), t(n, 1e9);
        c[0] = f[0], t[0] = 0;
        priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
        pq.push({f[0], 0, 0}); // {cost, time, node}

        while(!pq.empty()) {
            ar<int, 3> u = pq.top();
            pq.pop();

            for(ar<int, 2> v: adj[u[2]]) {
                if(u[1]+v[1] > maxTime) continue;

                // cost effective
                if(u[0] + f[v[0]] < c[v[0]]) {
                    c[v[0]] = u[0] + f[v[0]];
                    pq.push({u[0]+f[v[0]], u[1]+v[1], v[0]});
                }
                // time effective, cost may not be effective in this curr time
                // but later this time can give cost effective path
                else if(u[1] + v[1] < t[v[0]]) {
                    t[v[0]] = u[1] + v[1];
                    pq.push({u[0]+f[v[0]], t[v[0]], v[0]});
                }
            }
        }

        return c[n-1] == 1e9 ? -1 : c[n-1];
    }
};
