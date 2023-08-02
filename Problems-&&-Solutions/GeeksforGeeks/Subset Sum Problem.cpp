/*
Problem Statement: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

This is 0-1 Knapsack Problem (for more details/or different approaches visit the below GitHub Link:
    - Problem: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
    - GitHub(Soln): https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/GeeksforGeeks/0%20-%201%20Knapsack%20Problem.cpp
*/
class Solution{   
public:
    bool isSubsetSum(vector<int> a, int s){
        int n = (int)a.size();
        vector<bool> dp(s+1, false);
        dp[0] = true;
        for(int i=0; i<n; ++i) {
            for(int j=s; j>0; --j) {
                int exclude = dp[j];
                int include = (j >= a[i]) ? dp[j-a[i]] : false;
                dp[j] = exclude | include;
            }
        }
        return dp[s];
    }
};
