class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        vector<vector<int>> answer;
        for(int i=0; i<m; ++i) {
            vector<int> tmp;
            for(int j=0; j<n; ++j) {
                unordered_set<int> topLeft;
                int r=i-1, c=j-1;
                while(r>=0 && c>=0) {
                    topLeft.insert(grid[r][c]);
                    --r, --c;
                }
                
                unordered_set<int> bottomRight;
                r=i+1, c=j+1;
                while(r<m && c<n) {
                    bottomRight.insert(grid[r][c]);
                    ++r, ++c;
                }
                
                tmp.push_back(abs((int)topLeft.size() - (int)bottomRight.size()));
            }
            
            answer.push_back(tmp);
        }
        
        return answer;
    }
};
