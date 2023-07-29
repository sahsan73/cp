/*******
Problem Statement: https://leetcode.com/problems/house-robber/description/

0/1 Knapsack Problem
*******/
/*
APPROACH: DYNAMIC PROGRAMMING (SPACE OPTIMIZED)
    - If you noticed, we are only accessing previous two elements (i-1)th and (i-2)th for the current ith element.

COMPLEXITY:
    - TC = O(n);
    - SC = O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        //  (i-1)th     (i-2)th
        int p1=nums[0], p2=0;
        for(int i=1; i<n; ++i) {
            int include = nums[i] + p2;
            int exclude = p1;
            int curr = max(include, exclude);

            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up(Iteration + Tabulation)

COMPLEXITY:
    - TC = O(n)
    - SC = O(n)
*/
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i=1; i<n; ++i) {
            int include = nums[i] + (i>=2?dp[i-2]:0);
            int exclude = dp[i-1];
            dp[i] = max(include, exclude);
        }
        return dp[n-1];
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down(Recursion + Memoization)

COMPLEXITY:
    - TC = O(n)
    - SC = O(n)
*/
class Solution {
private:
    int dfs(int i, vector<int> &nums, vector<int> &dp) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int include = nums[i] + dfs(i-2, nums, dp);
        int exclude = dfs(i-1, nums, dp);
        return dp[i] = max(include, exclude);
    }

public:
    int rob(vector<int> &nums) {
        int n = (int)nums.size();
        vector<int> dp(n, -1);
        return dfs(n-1, nums, dp);
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: Recursion

VERDICT: TLE
*/
class Solution {
private:
    int dfs(int i, vector<int> &nums) {
        if(i < 0) return 0;

        int include = nums[i] + dfs(i-2, nums);
        int exclude = dfs(i-1, nums);
        return max(include, exclude);
    }

public:
    int rob(vector<int> &nums) {
        int n = (int)nums.size();
        return dfs(n-1, nums);
    }
};
