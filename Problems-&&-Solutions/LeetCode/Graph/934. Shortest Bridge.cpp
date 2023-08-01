/*
Problem Statement: https://leetcode.com/problems/shortest-bridge/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: 0-1 BFS
*/
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
#define ar array

class Solution {
public:
    int shortestBridge(vector<vector<int>> &grid) {
        int n = (int)grid.size();
        vector<vector<int>> d(n, vector<int>(n, 1e9)); // d[i][j]==1e9 means cell NOT visited
        deque<ar<int, 2>> q;
        // find the starting point to start bfs traversal
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1) {
                    q.push_front({i, j});
                    d[i][j] = 0;

                    goto x;
                }
            }
        }
        x:;

        auto inbound = [&](int r, int c) {
            return (r>=0 && r<n && c>=0 && c<n);
        };

        bool first_island_found = false;
        while(!q.empty()) {
            ar<int, 2> u = q.front();
            q.pop_front();

            if(grid[u[0]][u[1]] == 0) {
                // first island found
                first_island_found = 1;
            } else if(first_island_found && grid[u[0]][u[1]]) {
                // second island found
                return d[u[0]][u[1]];
            }

            for(int k=0; k<4; ++k) {
                int nr = u[0] + d4i[k];
                int nc = u[1] + d4j[k];
                if(inbound(nr, nc) && d[nr][nc]==1e9) {
                    d[nr][nc] = min(d[nr][nc], d[u[0]][u[1]]);
                    if(grid[nr][nc] == 0) {
                        ++d[nr][nc];
                        q.push_back({nr, nc});
                    } else {
                        q.push_front({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
