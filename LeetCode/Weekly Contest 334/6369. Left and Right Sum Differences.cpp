class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int ts = 0;
        for(int x: nums) ts += x;
        
        int ls=0;
        vector<int> ans;
        for(int x: nums) {
            int rs = ts - ls - x;
            ans.push_back(abs(rs-ls));
            
            ls += x;
        }
        return ans;
    }
};
