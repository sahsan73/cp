/*
SOME BASIC OF MATRIX MULTIPLICATION:
    - Suppose of we have two matrices A (order = m1 * n1) and B (order = m2 * n2)
    - We can multiply A and B only if they are compatible i.e., n1==m2.
    - 
    - Order of new matrix = m1*n2, 
    - Number of multiplications = m1*n1*n2

Note: In this problem, we are NOT actually multiplying matrices.
      Our goal is only to determine an order for multiplying matrices that has the LOWEST cost.
      
Problem:
    - Suppose we have n matrices to multiply <A1,A2,...,An>
    - Dimension, d = [d0, d1, d2, d3,...., dn]    
    - Order of matrix Ai = d[i-1] * d[i], where 1<=i<=n

WHY DOES IT MATTER? 
    - Consider we have chain of three matrices A1(10 * 100), A2(100 * 5) and A3(5*50)
    - Number of scalar multiplications if we multiply a/c to ((A1*A2)*A3) = 10*100*5 [for A1*A2] + 10*5*50 [for X*A3], where X = A1*A2
                                                                          = 7500
                                       
                                       if we multimply a/c to (A1*(A2*A3)) = 100*5*50[for A2*A3] + 10*100*50[for A1*X], where X = A2*A3
    
    
    - It is clear that multiplication order ((A1*A2)*A3) is 10x faster than (A1*(A2*A3))
*/


// ITERATIVE IMPLEMENTATION



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSIVE IMPLEMENTATION
int dfs(vt<int> &arr, int i, int j, vt<vt<int>> &dp) {
    if(i==j) return 0;
    if(dp[i][j] != 1e9) return dp[i][j];
    
    for(int k=i; k<j; ++k) {
        int res = dfs(arr,i,k,dp) + dp(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        dp[i][j] = min(dp[i][j], res);
    }
    return dp[i][j];
}

// mcm ==> matrix chain multiplication
int mcm(vt<int> &arr) {
    int n = (int)arr.size();
    vt<vt<int>> dp(n, vt<int>(n, 1e9));
    return dfs(arr,1,n-1,dp);
}





/*
SOME OF THE PROBLEMS BASED ON MATRIX CHAIN PROBLEM:
    [1]==> 312. Burst Balloons (LeetCode)

    [2]==> 1039. Minimum Score Triangulation of Polygon (LeetCode)



*/
