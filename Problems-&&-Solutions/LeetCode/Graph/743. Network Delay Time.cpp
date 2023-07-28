/*
APPROACH: Dijkstra's Algorithm

COMPLEXITY:
    - TC = O(mlogn)
*/

const int mxN=100;
#define ar array

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
        vector<ar<int, 2>> adj[mxN];
        for(auto &e: edges) {
            adj[--e[0]].push_back({e[2], --e[1]});
        }

        vector<int> tt(n, 1e9); // time taken to reach node u
        priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
        pq.push({0, --k});
        tt[k] = 0;
        while(!pq.empty()) {
            ar<int, 2> u = pq.top();
            pq.pop();
            for(ar<int, 2> v: adj[u[1]]) {
                if(u[0] + v[0] < tt[v[1]]) {
                    tt[v[1]] = u[0] + v[0];
                    pq.push({tt[v[1]], v[1]});
                }
            }
        }

        for(int i=0; i<n; ++i)
            cout << tt[i] << " ";
        cout << "\n";

        int answer = *max_element(tt.begin(), tt.end());
        return answer == 1e9 ? -1 : answer;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BELLMAN-FORD ALGORITHM

COMPLEXITY:
    - TC = O(nm)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
        vector<int> tt(n, 1e9);
        tt[--k] = 0;
        for(int i=0; i<n-1; ++i) {
            for(auto &e: edges) {
                int u = e[0]-1, v = e[1]-1;
                int w = e[2];
                if(tt[u]<1e9 && tt[u]+w<tt[v]) {
                    tt[v] = tt[u] + w;
                }
            }
        }

        int answer = *max_element(tt.begin(), tt.end());
        return answer < 1e9 ? answer : -1;
    }
};
