/*
                             n = 1     2     3      4      5     ...
    Total no. of colored cells = 1  +  4  +  8  +  12  +  16  +  ...
                               = 1 + 4*(1 + 2 + 3 + ..... + n-1)
                               = 1 + 2*n*(n-1)
*/
class Solution {
public:
    long long coloredCells(int n) {
        long long N = (long long)n;
        return 2*N*(N-1) + 1;
    }
};
