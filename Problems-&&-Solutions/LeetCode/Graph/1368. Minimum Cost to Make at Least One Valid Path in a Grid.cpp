/*
Problem Statement: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: 0-1 BFS
*/
#define ar array
int m, n;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
int cost[100][100];

class Solution {
public:
    int minCost(vector<vector<int>> &grid) {
        m = (int)grid.size(), n = (int)grid[0].size();
        memset(cost, 0x3f, sizeof(cost));

        auto inbound = [&](int r, int c) {
            return (r>=0 && r<m && c>=0 && c<n);
        };

        auto free_move = [](int k, int dr) {
            return ((k==0 && dr==4) || (k==1 && dr==1) || (k==2 && dr==3) || (k==3 && dr==2));
        };

        deque<ar<int, 2>> q;
        q.push_front({0, 0});
        cost[0][0] = 0;
        while(!q.empty()) {
            ar<int, 2> u = q.front();
            q.pop_front();
            if(u[0]==m-1 && u[1]==n-1) return cost[m-1][n-1];

            for(int k=0; k<4; ++k) {
                int nr = u[0] + d4i[k];
                int nc = u[1] + d4j[k];
                // since path need NOT to be shortest, we're using cost[nr][nc] > cost[u[0]][u[1]] which
                // may visit the same cell multiple times to get minimum cost --> Like Dijkstra's Algorithm
                // If shotest path need, we would use cost[nr][nc] >= 1e9, which would ensure that we visit
                // each cell once.
                if(inbound(nr, nc) && cost[nr][nc]>cost[u[0]][u[1]]) {
                    cost[nr][nc] = cost[u[0]][u[1]];
                    if(free_move(k, grid[u[0]][u[1]])) {
                        q.push_front({nr, nc});
                    } else {
                        ++cost[nr][nc];
                        q.push_back({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
