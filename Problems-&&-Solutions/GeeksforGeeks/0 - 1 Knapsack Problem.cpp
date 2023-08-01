/*
Problem Statement: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Further thing to notice that in case of include the ith number in our subsequence, i.e., [j-a[i]] --> we are basically accessing
previous columns data. So if we start traversing backward, our previous columns data will be intact and can be used efficiently
which is obviously NOT possible with the forward iteration.
*/
const int mxN = 1e3, mxW = 1e3; 

class Solution {
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        // Your code here
        int dp[mxW+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; ++i) {
            for(int j=W; j>0; --j) {
                int exclude = dp[j];
                int include = (j >= wt[i-1]) ? val[i-1] + dp[j-wt[i-1]] : 0;
                
                dp[j] = max(exclude, include);
            }
        }
        
        return dp[W];
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
In Bottom-Up Implementation #1, if we notice, we are only accessing two rows of dp table. So, we can take advantage of this and
space optimize of our code!

COMPLEXITY:
    - TC = O(n*w)
    - SC = O(2*w) ==> O(w)

Bottom-Up Implementation #2
*/
const int mxN = 1e3, mxW = 1e3; 

class Solution {
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        // Your code here
        int dp[2][mxW+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=W; ++j) {
                int exclude = dp[0][j];
                int include = (j >= wt[i-1]) ? val[i-1] + dp[0][j-wt[i-1]] : 0;
                
                dp[1][j] = max(exclude, include);
            }
            
            for(int j=0; j<=W; ++j)
                dp[0][j] = dp[1][j];
        }
        
        return dp[1][W];
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementaton: Bottom-Up(Iteration + Tabulation)

COMPLEXITY:
    - TC = O(n*w)
    - SC = O(n*w)

Bottom-Up Implementation #1
*/
const int mxN = 1e3, mxW = 1e3; 

class Solution {
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        // Your code here
        int dp[mxN+1][mxW+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=W; ++j) {
                int exclude = dp[i-1][j];
                int include = (j >= wt[i-1]) ? val[i-1] + dp[i-1][j-wt[i-1]] : 0;
                
                dp[i][j] = max(exclude, include);
            }
        }
        
        return dp[n][W];
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down(Recursion + Memoization)

COMPLEXITY:
    - TC = O(n*w)
    - SC = O(n*w)
*/
const int mxN = 1e3, mxW = 1e3;

class Solution {
private:
    int dp[mxN][mxW+1];
    
    int dfs(int i, int W, int wt[], int val[]) {
        if(i<0 || W<=0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        int exclude = dfs(i-1, W, wt, val);
        int include = (W >= wt[i]) ? val[i] + dfs(i-1, W-wt[i], wt, val) : 0;
        
        return dp[i][W] = max(exclude, include);
    }
    
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        // Your code here
        memset(dp, -1, sizeof(dp));
        return dfs(n-1, W, wt, val);
        
    }
};
