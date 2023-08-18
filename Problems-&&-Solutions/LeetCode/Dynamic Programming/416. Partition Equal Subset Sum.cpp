/*
Problem Statement: https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KNAPSACK

COMPLEXITY:
    - TC = O(n*wt)
    - SC = O(n)
*/
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = (int)nums.size();
        int wt = accumulate(nums.begin(), nums.end(), 0);
        if(wt&1) return 0;

        // since we need to partition the array into two equal subsets sum
        // so each will have sum (wt / 2)
        // now our task boils down to find a subset whose sum equals wt/2
        wt /= 2;
        bool dp[20000] = {};
        dp[0] = 1;
        for(int i=0; i<n; ++i) {
            for(int j=wt; ~j; --j) {
                int exclude = dp[j];
                int include = (j >= nums[i]) ? dp[j-nums[i]] : 0;
                dp[j] = exclude | include;
            }
        }
        return dp[wt];
    }
};
