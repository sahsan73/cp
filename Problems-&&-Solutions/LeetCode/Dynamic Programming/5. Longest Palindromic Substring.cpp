/*
Problem Statement: https://leetcode.com/problems/longest-palindromic-substring/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
 * dp[i][j] ==> true/false whether the substring s[i....j] is palidrome or not
 *
 * Core concept: s[i....j] is a palidromic substring if-and-only-if s[i+1....j-1]
 * is palindrome (i.e., dp[i+1][j-1] is TRUE) and s[i] == s[j]
*/
class Solution {
private:
    int start, mxlen;
    int n, dp[1000][1000];

public:
    string longestPalindrome(string s) {
        n = (int)s.size();
        memset(dp, 0, sizeof(dp));
        // substrings with length 1 will always be palindromic
        for(int i=0; i<n; ++i) dp[i][i] = 1;
        start = 0, mxlen = 1;
        /*
         * check for substrings having length of 2
         *
         * why is it required??
         *      - Suppose we check for the substring t = "sa" --> i = 0, j = 1
         *      - s[i+1][j-1] --> s[1][0] (or dp[1][0]) is actually a reverse substring
         *      - which is obviously not required.
        */
        for(int i=0; i<n-1; ++i) {
            dp[i][i+1] = s[i]==s[i+1];
            if(dp[i][i+1]) start = i, mxlen = 2;
        }

        for(int len=3; len<=n; ++len) {
            for(int i=0; i<n-len+1; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
                if(dp[i][j] && len>mxlen) {
                    start = i;
                    mxlen = len;
                }
            }
        }
        return s.substr(start, mxlen);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: EXPAND AROUND CENTER
    - The idea behind is that, take a center and expand bidirectionally at the same time
    - Suppose, substring [i, i+1, ..., j-1, j] is palindrome then [i+1, ..., j-1] must be a palindrome
    - For example,
        - string s = "abcba" is palindrome, ==> "bcb" is palindrome and so is "c"
          Note: character 'c' is the center in this case (odd length substrings)
          
        - string s = "abba" is a palindrome, ==> "bb" is a palindrome ==> "" is a palindrome
          Note: center lies between two 'b' characters, in this case (even length substrings)

COMPLEXITY:
    - TC = O(n^2)
    - SC = O(1)
*/
class Solution {
private:
    int n;
    int start, mxlen;

    void expand_bidir(string &s, int i, int j) {
        while(i>=0 && j<n && s[i]==s[j]) {
            int len = j-i+1;
            if(len > mxlen) {
                start = i;
                mxlen = len;
            }

            --i, ++j;
        }
    }

public:
    string longestPalindrome(string s) {
        n = (int)s.size();
        left = 0, mxlen = 1;

        for(int i=0; i<n; ++i) {
            // check odd length substrings
            expand_bidir(s, i, i);

            // check even length substrings
            expand_bidir(s, i, i+1);
        }

        return s.substr(left, mxlen);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE
    - Find all the substrings of the given string, which is n*(n+1)/2 where n represents length
    - Check each substring if it is a palindrome simultaneously keeping track of the palindromic
      substring of maximum length.

COMPLEXITY:
    - TC = O(n^3)
    - SC = O(1)
*/
class Solution {
private:
    int start, mxlen;

    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        start =0, mxlen = 1;

        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                int len = j-i+1;
                if(len>mxlen && isPalindrome(s, i, j)) {
                    start = i;
                    mxlen = len;
                }
            }
        }

        return s.substr(start, mxlen);
    }
};
