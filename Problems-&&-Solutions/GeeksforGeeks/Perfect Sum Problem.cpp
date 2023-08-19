/*
Problem Statement: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Bottom-Up(Iteration + Tabulation)
*/
class Solution {
private:
    const int M = 1000000007;
    
public:
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0; i<=n; ++i) dp[i][0] = 1;
        
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=sum; ++j) {
                int exclude = dp[i-1][j];
                int include = (j >= arr[i-1]) ? dp[i-1][j-arr[i-1]] : 0;
                
                dp[i][j] = (exclude + include)%M;
            }
        }
        
        return dp[n][sum];
	}
	  
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Implementation: Top-Down(Recursion + Memoization)
*/
class Solution {
private:
    vector<vector<int>> dp;
    const int M = 1000000007;

    /*
        - Don't include the base case:
                    if(s == 0) return 0;

        - Think of a case when arr[] = {0, 0, 0}, and sum = 0; with the above basecase used answer will be 1,
          however, the actual answer should be 7.
    */
    int cntSubsets(int i, int a[], int s) {
        if(i < 0)
            return s == 0;
        if(~dp[i][s])
            return dp[i][s];
        
        int exclude = cntSubsets(i-1, a, s);
        int include = (s >= a[i]) ? cntSubsets(i-1, a, s-a[i]) : 0;
        return dp[i][s] = (exclude + include)%M;
    }
    
public:
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        dp.assign(n, vector<int>(sum+1, -1));
        return cntSubsets(n-1, arr, sum);
	}
	  
};
