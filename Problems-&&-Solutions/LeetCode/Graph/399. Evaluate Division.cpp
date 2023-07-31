/*
Problem Statement: https://leetcode.com/problems/evaluate-division/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE
    - Run DFS/BFS for every pair of (src, dst}
*/
const int mxN = 50;
const double inf = std::numeric_limits<double>::infinity();
using ll=long long;

class Solution {
private:
    bool dfs(int u, int dst, ll &vis, vector<pair<int, double>> adj[mxN], double &val) {
        vis |= (1<<u);
        if(u == dst) return true;
        for(auto &it: adj[u]) {
            int v = it.first;
            if(vis&(1<<v)) continue;
            double w = it.second;
            val *= w;
            if(dfs(v, dst, vis, adj, val)) {
                return val;
            }

            val /= w;
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // cout << values.size() << "\n";
        vector<pair<int, double>> adj[mxN];
        unordered_map<string, int> mp;
        int id = 0, i=0;
        for(auto &e: equations) {
            int u = (mp.count(e[0]) > 0) ? mp[e[0]] : mp[e[0]] = id++;
            int v = (mp.count(e[1]) > 0) ? mp[e[1]] : mp[e[1]] = id++;

            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0/values[i]});
            ++i;
        }

        vector<double> answer;
        for(auto &q: queries) {
            if(!mp.count(q[0]) || !mp.count(q[1])) {
                answer.push_back(-1.0);
                continue;
            }

            int u = mp[q[0]], v = mp[q[1]];
            double val = 1.0;
            ll vis = 0LL;
            if(dfs(u, v, vis, adj, val)) {
                answer.push_back(val);
            } else {
                answer.push_back(-1.0);
            }
        }
        return answer;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: FLOYD-WARSHALL ALGORITHM

VERDICT: WA
First Test Case to Report WA:
    [["b","a"],["c","b"],["d","c"],["e","d"],["f","e"],["g","f"],["h","g"],["i","h"],["j","i"],["k","j"],["k","l"],["l","m"],["m","n"],["n","o"],["o","p"],["p","q"],["q","r"],["r","s"],["s","t"],["t","u"]]
    [1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05]
    [["a","u"]]
*/
const int mxN = 50;
const double inf = std::numeric_limits<double>::infinity();

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<pair<int, double>> adj[mxN];
        unordered_map<string, int> mp;
        int id = 0, i=0;
        vector<vector<double>> dp(mxN, vector<double>(mxN, inf));
        for(int i=0; i<mxN; ++i) dp[i][i] = 1.0;
        for(auto &e: equations) {
            int u = (mp.count(e[0]) > 0) ? mp[e[0]] : mp[e[0]] = id++;
            int v = (mp.count(e[1]) > 0) ? mp[e[1]] : mp[e[1]] = id++;
            // adj[u].push_back({u, values[i++]});
            dp[u][v] = values[i];
            dp[v][u] = 1.0/values[i];
            ++i;
        }
        
        int n = id;
        for(int x=0; x<n; ++x) {
            for(int u=0; u<n; ++u) {
                for(int v=0; v<n; ++v) {
                    if(dp[u][x]==inf || dp[x][v]==inf)
                        continue;
                    dp[u][v] = min(dp[u][v], dp[u][x]*dp[x][v]);
                }
            }
        }

        vector<double> answer;
        for(auto &q: queries) {
            if(!mp.count(q[0]) || !mp.count(q[1])) {
                answer.push_back(-1.0);
                continue;
            }
            
            double val = dp[mp[q[0]]][mp[q[1]]];
            answer.push_back(val==inf ? -1.0 : val);
        }
        return answer;
    }
};
