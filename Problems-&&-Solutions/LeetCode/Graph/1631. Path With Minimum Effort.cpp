/*
APPROACH: Dijkstra's Algorithm

COMPLEXITY:
    - TC = O(mlogn)
*/
#define vt vector

class Solution {
private:
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = (int)heights.size(), n = (int)heights[0].size();
        vector<vector<int>> eff(m, vector<int>(n, 1e9));
        eff[0][0] = 0;

        auto inbound = [&](int r, int c) {
            return (r>=0 && r<m && c>=0 && c<n);
        };

        priority_queue<vt<int>, vt<vt<int>>, greater<vt<int>>> pq;
        pq.push({0, 0, 0});  // {mxDiff, r, c}
        while(!pq.empty()) {
            int currDiff = pq.top()[0];
            int r = pq.top()[1], c = pq.top()[2];
            pq.pop();

            for(int k=0; k<4; ++k) {
                int nr = r + d4i[k];
                int nc = c + d4j[k];
                if(!inbound(nr, nc)) continue;

                int diff = abs(heights[nr][nc] - heights[r][c]);
                int newDiff = max(currDiff, diff);
                if(newDiff < eff[nr][nc]) {
                    eff[nr][nc] = newDiff;
                    pq.push({newDiff, nr, nc});
                }
            }
        }
        return eff[m-1][n-1];
    }
};
