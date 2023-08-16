/*
Problem Statement: https://www.hackerrank.com/challenges/the-power-sum/problem?isFullScreen=true

APPROACH:
    1^N + 2^N + 3^N + ... + Y^N = X
    We can find out max value of Y, when there exist a single solution for X (i.e., Y^N = X)
                              Y <= X^(1/N)

COMPLEXITY:
    TC = 2^Y
    SC = O(1)
*/

int solve(int i, int Y, int X, int N) {
    if(X == 0) return 1;
    if(i>Y || X<0) return 0;
    
    int exclude = solve(i+1, Y, X, N);
    int include = solve(i+1, Y, X-pow(i, N), N);
    
    return exclude + include;
}

int powerSum(int X, int N) {
    int Y = pow(X, 1.0/N);
    return solve(1, Y, X, N);
}
