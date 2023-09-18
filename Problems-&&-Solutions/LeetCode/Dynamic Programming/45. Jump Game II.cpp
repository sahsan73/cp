/*
Problem Statement: https://leetcode.com/problems/jump-game-ii/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: GREEDY

COMPLEXITY:
    - TC = O(n)
    - SC = O(n)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0; // current window boundary - starting point

        int answer = 0;
        while(r < nums.size()-1) {
            int farthest = -1;
            for(int i = l; i <= r; ++i)
                farthest = max(farthest, i + nums[i]);

            ++answer;

            l = r + 1;
            r = farthest;
        }
        return answer;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING

COMPLEXITY:
    - TC = O(n * max(nums[i]))
    - SC = O(n)
*/
class Solution {
public:
    int jump(vector<int> &nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= nums[i]; ++j) {
                if(i + j >= n)
                    break;
                
                dp[i+j] = min(dp[i+j], 1 + dp[i]);
            }
        }
        return dp[n-1];
    }
};
