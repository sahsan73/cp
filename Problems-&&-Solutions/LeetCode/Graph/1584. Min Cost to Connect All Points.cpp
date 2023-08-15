/*
Problem Statement: https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: MST
*/
class Solution {
private:
    int p[1000000], s[1000000];
    vector<array<int, 3>> e;

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

public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        e.clear();
        int n = (int)points.size();
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                e.push_back({i, j, d});
            }
        }

        sort(e.begin(), e.end(), [](auto &e1, auto &e2){
            return e1[2] < e2[2];
        });
        int answer = 0;
        iota(p, p+n*n, 0);
        fill(s, s+n*n, 1);
        for(int i=0; i<e.size(); ++i) {
            if(join(e[i][0], e[i][1]))
                answer += e[i][2];
        }
        return answer;
    }
};
