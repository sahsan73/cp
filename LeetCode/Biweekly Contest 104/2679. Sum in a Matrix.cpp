class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) {
        for(auto &v: nums) sort(v.begin(), v.end());
        
        int ans = 0;
        for(int j=0; j<nums[0].size(); ++j) {
            int mx = 0;
            for(int i=0; i<nums.size(); ++i)
                mx = max(mx, nums[i][j]);
            
            ans += mx;
        }
        return ans;
    }
};
