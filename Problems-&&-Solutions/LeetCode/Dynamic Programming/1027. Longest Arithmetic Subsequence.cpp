/*
Problem Statement: https://leetcode.com/problems/longest-arithmetic-subsequence/description/
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestArithSeqLength(vector<int> &a) {
        int n = (int)a.size();
        unordered_map<int, int> dp[1000]; // dp[i] ==> {{diff1, l1}, {diff2, l2}, ... }
        int answer = 0;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                int diff = a[i] - a[j];
                dp[i][diff] = max(dp[i][diff], dp[j][diff]+1);
                
                answer = max(answer, dp[i][diff]);
            }
        }
        return answer+1;
    }
};
