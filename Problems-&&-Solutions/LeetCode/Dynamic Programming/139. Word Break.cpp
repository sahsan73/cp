/*
Problem Statement: https://leetcode.com/problems/word-break/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up (Iteration + Tabulation)
*/
class Solution {
private:
    unordered_set<string> st;
    int n, dp[300];

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        st.clear();
        for(auto &w: wordDict)
            st.insert(w);
        n = (int)s.size();
        
        // dp[i] = can substring [0....i] be segmented into a space-separated
        // sequence of one or more dicionary words
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j<=i; ++j) {
                dp[i] = dp[j-1] && st.count(s.substr(j-1, i-j+1));
                if(dp[i])
                    break;
            }
        }
        return dp[n];
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down(Recursion + Memoization)
*/
class Solution {
private:
    unordered_set<string> st;
    int n, dp[300];

    bool dfs(int i, string &s) {
        if(i == n || st.count(s.substr(i)))
            return 1;
        if(~dp[i])
            return dp[i];
        
        for(int len = 1; len <= n-i; ++len) {
            if(st.count(s.substr(i, len)) && dfs(i+len, s))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        st.clear();
        for(auto &w: wordDict)
            st.insert(w);
        n = (int)s.size();

        memset(dp, -1, sizeof(dp));
        return dfs(0, s);
    }
};
