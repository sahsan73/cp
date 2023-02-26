class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        
        int ans=0, j=n-1;
        for(int i=n/2-1; ~i; --i) {
            if(2*nums[i] <= nums[j]) {
                ans += 2;
                --j;
            }
        }
        
        return ans;
    }
};
