/*
Problem Statement: https://leetcode.com/problems/minimum-height-trees/description/

This problem is same as CSES problem: Distance Tree I
    - Problem Statement: https://cses.fi/problemset/task/1132
    - Solution: https://github.com/sahsan73/cp/blob/main/Problems-&&-Solutions/CSES/Tree%20Algorithms/Tree%20Distances%20I.cpp
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: RE-ROOTING OF TREES
*/
const int mxN = 2e4;
#define ar array

class Solution {
private:
    int n, d[mxN], ans[mxN]; // d[i] = height of ith node
    vector<int> adj[mxN];

    void init(int n, vector<vector<int>> &edges) {
        this->n = n;
        for(int i=0; i<n; ++i) {
            d[i] = 0, ans[i] = 0;
            adj[i].clear();
        }

        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int u=0, int p=-1) {
        for(int v: adj[u]) {
            if(v == p) continue;
            // d[v] = d[u] + 1;
            dfs(v, u);
            d[u] = max(d[u], d[v]+1);
        }
    }

    void dfs2(int u=0, int p=-1, int pd=0) {
        ans[u] = max(d[u], pd);
        vector<ar<int, 2>> w = {{pd, -1}};
        for(int v: adj[u]) {
            if(v == p) continue;
            cout << u << ": " << "saquib ahsan" << "\n";
            w.push_back({d[v]+1, v});
        }
        // w.push_back({0, -1});
        sort(w.begin(), w.end(), greater<ar<int, 2>>());

        for(int v: adj[u]) {
            if(v == p) continue;
            dfs2(v, u, w[0][1]==v?w[1][0]+1:w[0][0]+1);
        }
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        init(n, edges);

        dfs();
        dfs2();

        int mn = 1e9;
        for(int i=0; i<n; ++i) mn = min(mn, ans[i]);
        vector<int> answer;
        for(int i=0; i<n; ++i) {
            if(ans[i] == mn)
                answer.push_back(i);
        }
        return answer;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: MULTI-SOURCE BFS
    - Read editorial for explanation!!
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> adj[n], deg(n, 0);
        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++deg[u], ++deg[v];
        }

        vector<bool> vis(n, false);
        queue<int> q;
        for(int i=0; i<n; ++i) {
            // deg[i] < 1 handles a case where n == 1 i.e., single node and no edges
            if(deg[i] <= 1) { // both deg[i]==1 and adj[i].size() == 1 are same!
                q.push(i);
                vis[i] = 1;
            }
        }

        vector<int> answer;
        while(!q.empty()) {
            int sz = (int)q.size();
            answer.clear();
            while(sz--) {
                int u = q.front();
                q.pop();
                answer.push_back(u);

                for(int v: adj[u]) {
                    --deg[v];
                    if(deg[v] == 1)
                        q.push(v);
                }
            }
        }
        return answer;
    }
};