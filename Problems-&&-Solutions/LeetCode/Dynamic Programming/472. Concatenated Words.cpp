/*
Problem Statement: https://leetcode.com/problems/concatenated-words/description/

An extension of the LeetCode problem, 139. Word Break
    - problem statement: https://leetcode.com/problems/word-break/
    - solution: https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/LeetCode/Dynamic%20Programming/139.%20Word%20Break.cpp
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Bottom - Up Implementation
*/
class Solution {
private:
    unordered_set<string> st;
    int n, dp[31], cnts[31];

    bool check(string &s) {
        n = (int)s.size();
        memset(dp, 0, sizeof(dp));
        memset(cnts, 0, sizeof(cnts));

        dp[0] = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                if(dp[j-1] && st.count(s.substr(j-1, i-j+1))) {
                    dp[i] = 1;
                    cnts[i] = max(cnts[i], 1 + cnts[j-1]);
                }
            }
        }
        return dp[n] && cnts[n]>1;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        st.clear();
        for(auto &w: words)
            st.insert(w);
        
        vector<string> answer;
        for(auto &w: words) {
            st.erase(w);
            if(check(w))
                answer.push_back(w);
            st.insert(w);
        }
        return answer;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Top-Down Implementation
*/
class Solution {
private:
    unordered_set<string> st;
    int n, dp[31];

    // this boolean value f ensures that the word is comprised
    // entirely of atleast two shorter words
    // first time the loop will iterate for the length j=1, n-1 i.e, it has to be atleast two shorter words
    bool dfs(int i, string s, bool f) {
        if(i == n)
            return true;
        if(~dp[i])
            return dp[i];

        for(int len=1; len<=n-i-f; ++len) {
            if(st.count(s.substr(i, len)) && dfs(i+len, s, 0))
                return dp[i]=1;
        }
        return dp[i]=0;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        st.clear();
        for(auto &word: words)
            st.insert(word);

        vector<string> answer;
        for(auto word: words) {
            n = (int)word.size();
            memset(dp, -1, sizeof(dp));
            if(dfs(0, word, 1))
                answer.push_back(word);
        }
        return answer;
    }
};
