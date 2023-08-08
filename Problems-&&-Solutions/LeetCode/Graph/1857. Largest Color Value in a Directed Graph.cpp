/*
Problem Statement: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: TOPO SORT
*/
class Solution {
private:
    const int mxN = 1e5;
    int n;

public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        n = (int)colors.size();
        vector<int> adj[mxN], indeg(n, 0), order;
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }

        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(int v: adj[u]) {
                --indeg[v];
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        if(order.size() != n) return -1;

        array<int, 26> dp[mxN];
        for(int i=0; i<n; ++i)
            dp[i].fill(0);
        int answer = 0;
        for(int u: order) {
            answer = max(answer, ++dp[u][colors[u]-'a']);
            for(int v: adj[u]) {
                for(int i=0; i<26; ++i)
                    dp[v][i] = max(dp[v][i], dp[u][i]);
            }
        }
        return answer;
    }
};
