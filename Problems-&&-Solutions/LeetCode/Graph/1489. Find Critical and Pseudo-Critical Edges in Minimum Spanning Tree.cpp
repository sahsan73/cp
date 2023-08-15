/*
Problem Statement: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
*/

class Solution {
private:
    int n, m;
    int p[100], s[100];

    int find(int u) {
        return u^p[u] ? p[u]=find(p[u]) : u;
    }

    bool join(int u, int v) {
        if((u=find(u)) == (v=find(v)))
            return 0;
        if(s[u] < s[v])
            swap(u, v);
        p[v] = u;
        s[u] += s[v];
        return 1;
    }

    // compute MST by including/excluding jth edge
    int computeMST(vector<vector<int>> &e, int j, bool include=0) {
        iota(p, p+n, 0);
        fill(s, s+n, 1);

        int mstWt = 0, cnt = 0;
        if(include) {
            join(e[j][0], e[j][1]);
            mstWt += e[j][2];
            ++cnt;
        }
        for(int i=0; i<m; ++i) {
            if(i == j) continue;

            if(join(e[i][0], e[i][1])) {
                mstWt += e[i][2];
                ++cnt;
            }
        }
        // count must be n-1 for connected MST <-- check for disconnected graph
        return cnt < n-1 ? 1e9 : mstWt;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &e) {
        this->n = n, m = (int)e.size();
        // we need to keep track of the original edge indices
        for(int i=0; i<m; ++i)
            e[i].push_back(i);
        sort(e.begin(), e.end(), [](auto &e1, auto &e2){
            return e1[2] < e2[2];
        });
        // calculate standart weight of MST
        int stdWt = computeMST(e, -1);

        // check every jth edge if it is a critical or a pseudo-critical edge.
        // the way we check it is, we will compute MST by excluding jth edges and
        // wll compare the value with the stdWt of MST
        vector<int> critical, pseudoCritical;
        for(int j=0; j<m; ++j) {
            int mstWtByExcluding = computeMST(e, j);
            // check if the jth edge is a critical edge
            if(mstWtByExcluding > stdWt) {
                critical.push_back(e[j][3]);
            } else { // check if the jth edge is a pseudo-critical edge
                int mstWtByIncluding = computeMST(e, j, 1);
                if(mstWtByIncluding == stdWt)
                    pseudoCritical.push_back(e[j][3]);
            }
        }
        vector<vector<int>> answer = {critical, pseudoCritical};
        return answer;
    }
};
