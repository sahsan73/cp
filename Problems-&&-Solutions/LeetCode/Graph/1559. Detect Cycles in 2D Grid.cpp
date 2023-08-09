/*
Problem Statement: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Detect cycle in an undirected graph
*/
class Solution {
private:
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
    int m, n;
    vector<vector<char>> grid;
    bool vis[500][500];
    
    bool inbound(int r, int c) {
        return (r>=0 && r<m && c>=0 && c<n);
    }

    bool dfs(int r, int c, int pr=-1, int pc=-1) {
        vis[r][c] = 1;
        for(int k=0; k<4; ++k) {
            int nr = r + d4i[k];
            int nc = c + d4j[k];
            if(!inbound(nr, nc) || grid[nr][nc]!=grid[r][c] || (nr==pr && nc==pc))
               continue;
            
            if(vis[nr][nc] || (!vis[nr][nc] && dfs(nr, nc, r, c)))
                return true;
            
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>> &grid) {
        m = (int)grid.size(), n = (int)grid[0].size();
        memset(vis, 0, sizeof(vis));
        this->grid = grid;

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(!vis[i][j] && dfs(i, j))
                    return true;
            }
        }
        return false;
    }
};
