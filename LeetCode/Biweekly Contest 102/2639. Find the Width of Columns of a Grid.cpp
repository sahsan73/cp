class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int j=0; j<grid[0].size(); ++j) {
            int mx = 0;
            for(int i=0; i<grid.size(); ++i) {
                string s = to_string(grid[i][j]);
                mx = max(mx, (int)s.size());
            }
            
            ans.push_back(mx);
        }
        
        return ans;
    }
};