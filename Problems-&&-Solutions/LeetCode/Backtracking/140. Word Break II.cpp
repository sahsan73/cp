/*
Problem Statement: https://leetcode.com/problems/word-break-ii/description/
*/

class Solution {
private:
    unordered_set<string> st;
    int n;
    vector<string> answer;

    void dfs(int i, string &s, string t) {
        if(i == n) {
            answer.push_back(t);
            return;
        }

        for(int len = 1; len <= n-i; ++len) {
            string t2 = s.substr(i, len);
            if(st.count(t2)) {
                dfs(i+len, s, t.empty()?t2:t+" "+t2);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        answer.clear(), st.clear();
        n = (int)s.size();
        for(auto &w: wordDict)
            st.insert(w);
        
        dfs(0, s, "");
        return answer;
    }
};
