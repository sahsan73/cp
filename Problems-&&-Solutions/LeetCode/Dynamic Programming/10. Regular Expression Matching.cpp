/*
Problem Statement: https://leetcode.com/problems/regular-expression-matching/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Iterative Implementation */
class Solution {
private:
    bool dp[21][21];

public:
    bool isMatch(string s, string p) {
        int n = (int)s.size(), m = (int)p.size();
        memset(dp, 0, sizeof(dp));
        s = "0" + s;
        p = "0" + p;

        dp[0][0] = 1; // case: s=="" && t==""
        /* cases: s=="", t=="a*", "a*b*", "a*b*c*", ....
         * We need to consider these because "a*", "a*b*", ... can
         * also represent ""(empty) string
         */
        for(int j=1; j<=m; ++j) {
            if(p[j] == '*')
                dp[0][j] = dp[0][j-2];
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(s[i]==p[j] || p[j]=='.') {
                    dp[i][j] |= dp[i-1][j-1];
                } else if(p[j] == '*') {
                    /* 0 occurrence of (j-1)th character,
                     * If we're going to skip the preceeding element, then we have jump by
                     * 2 i.e., the preceeding element and wildcard character (*)
                     */
                    dp[i][j] = dp[i][j-2];

                    // use ">= 1" occurrences of (j-1)th character
                    if(s[i]==p[j-1] || p[j-1]=='.')
                        dp[i][j] |= dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Recursive Implementation */
