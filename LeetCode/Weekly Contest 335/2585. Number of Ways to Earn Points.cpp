/*
APPROACH: DYNAMIC PROGRAMMING
    - Knapsack's application
*/
const int mod = 1e9 + 7;

class Solution {
public:
    int dfs(int i, vector<vector<int>> &arr, int t, vector<vector<int>> &dp) {
        if(t == 0) return 1;
        if(i>=arr.size() || t<0) return 0;
        if(dp[i][t] != -1) return dp[i][t];

        int res = 0;
        for(int j=0; j<=arr[i][0]; ++j) {
            res += dfs(i+1, arr, t-j*arr[i][1], dp);
            res %= mod;
        }
        return dp[i][t] = res;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = (int)types.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return dfs(0, types, target, dp);
    }
};
