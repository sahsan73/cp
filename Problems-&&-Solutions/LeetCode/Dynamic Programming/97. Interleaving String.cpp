/*
Problem Statement: https://leetcode.com/problems/interleaving-string/description/

extn. of LCS problem
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = (int)s1.size(), n = (int)s2.size();
        if(m+n != s3.size()) return 0;

        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=0; i<=m; ++i) {
            for(int j=0; j<=n; ++j) {
                if(i>=1 && s1[i-1] == s3[(i+j-1)] && dp[i-1][j])
                    dp[i][j] = 1;
                if(j>=1 && s2[j-1] == s3[(i+j-1)] && dp[i][j-1])
                    dp[i][j] = 1;
            }
        }
        return dp[m][n];
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down
*/
class Solution {
private:
    string s1, s2, s3;
    int dp[101][101];

    bool dfs(int i, int j) {
        if(i==-1 && j==-1) return 1;
        // if(i<0 || j<0) return 0; // case #: s1 = "ab", s2 = "def", and s3 = "defab"
        if(~dp[i+1][j+1]) return dp[i+1][j+1];

        bool res = 0;
        if(i>=0 && s1[i]==s3[i+j+1] && dfs(i-1, j))
            return dp[i+1][j+1] = 1;
        if(j>=0 && s2[j]==s3[i+j+1] && dfs(i, j-1))
            return dp[i+1][j+1] = 1;
        return dp[i+1][j+1] = 0;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        int m = (int)s1.size(), n = (int)s2.size();
        if(m + n != s3.size()) return false;
        
        // dp[i][j] = is interleaving of strings s1[0....i] and s2[0....j] form s3[0....k]
        // where k = i + j + 1 (logically and obviously)
        memset(dp, -1, sizeof(dp));
        return dfs(m-1, n-1);
    }
};
