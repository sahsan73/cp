/*
Problem Statement: https://leetcode.com/problems/palindrome-partitioning/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING

COMPLEXITY:
    - TC = O(n^3 * m)
    - SC = O(mn)
*/
#define vt vector
#define sz(x) (int)(x).size()

class Solution {
private:
    string s;
    int n;
    unordered_map<int, vt<vt<string>>> dp;

    bool isPalindrome(int i, int j) {
        for(; i < j; ++i, --j) {
            if(s[i]^s[j])
                return 0;
        }
        return 1;
    }

    vt<vt<string>> dfs(int i) {
        if(i >= n)
            return {{}};
        if(dp.count(i))
            return dp[i];
        
        vt<vt<string>> answer;
        for(int j = i; j < n; ++j) {
            if(isPalindrome(i, j)) {
                string t = s.substr(i, j-i+1);
                vt<vt<string>> res = dfs(j+1);

                for(auto &vs: res) {
                    vs.insert(vs.begin(), t);
                    answer.push_back(vs);
                }
            }
        }
        return dp[i] = answer;
    }

public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = (int)s.size();

        dp.clear();
        return dfs(0);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(2^n)
    - SC = O(mn)
*/
class Solution {
private:
    vector<vector<string>> answer;
    int n;
    string s;

    bool isPalindrome(int i, int j) {
        for(; i < j; ++i, --j) {
            if(s[i]^s[j])
                return false;
        }
        return true;
    }

    void dfs(int i, vector<string> &res) {
        if(i >= n) {
            answer.push_back(res);
            return;
        }

        for(int j=i; j<n; ++j) {
            if(isPalindrome(i, j)) {
                res.push_back(s.substr(i, j-i+1));
                dfs(j+1, res);

                res.pop_back(); // backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        answer.clear();
        n = (int)s.size();
        this->s = s;

        vector<string> res;
        dfs(0, res);
        return answer;
    }
};
