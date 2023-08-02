/*
Problem Statement: https://leetcode.com/problems/target-sum/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up (Iteration + 
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
In Top-Down Implementation #1, we had to use map data structure in order to cache/memoize the intermediate results since our
intermediate sum can be negative.

However, we can use one observation: maximum intermediate negative sum will happen when we use negative sign for all elements.
So, we will offset (sum of all elements) to allocate memory for dp table.

Given constraint:
    -1000 <= target <= 1000
    the way i am directly manipulating t value
        -2000(when all taken as neg) <= t <= 2000(when all taken as pos), as 0 <= sum(nums[i]) <= 1000 provided
    Let's make offset of 2000, then range of t will be
        0 <= t <= 4000

*/
class Solution {
private:
    int n, total, dp[20][4001];

    int dfs(int i, vector<int> &a, int t) {
        if(i == n) return t == 0;
        if(dp[i][2000+t] != -1) return dp[i][2000+t];

        int withPosSign = dfs(i+1, a, t-a[i]);
        int withNegSign = dfs(i+1, a, t+a[i]);

        return dp[i][2000+t] = withPosSign + withNegSign;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        n = (int)nums.size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, nums, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Intuition: 0/1 Knapsack
    - Implementation: Top-Down(Recursion + Memoization)

Suppose we have an input array, a[] = [1, 1, 1, 1, 1]
    - (+1 -1 +1)...[1, 1, 1]
    - (-1 +1 +1)...[1, 1, 1]
    - (+1 +1 -1)...[1, 1, 1]
    .....

COMPLEXITY:
    - TC = O(n*t)
    - SC = O(n*t)

Top-Down Implementation #1
*/
class Solution {
private:
    int n;
    map<pair<int, int>, int> dp; // dp[{i, t}] --> cnt ways in [i...n-1] whose sum t

    int dfs(int i, vector<int> &a, int t) {
        if(i == n) return t == 0;
        if(dp.count({i, t})) return dp[{i, t}];

        int withPosSign = dfs(i+1, a, t-a[i]);
        int withNegSign = dfs(i+1, a, t+a[i]);
        return dp[{i, t}] = withPosSign + withNegSign;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        n = (int)nums.size();
        return dfs(0, nums, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(2^n)
    - SC = O(1)
*/
class Solution {
private:
    int n;

    int dfs(int i, vector<int> &a, int t) {
        if(i == n) {
            return t == 0;
        }

        int withPosSign = dfs(i+1, a, t-a[i]);
        int withNegSign = dfs(i+1, a, t+a[i]);
        return withPosSign + withNegSign;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        n = (int)nums.size();
        return dfs(0, nums, target);
    }
};
