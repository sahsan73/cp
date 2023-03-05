class Solution {
public:
    int passThePillow(int n, int t) {
        t %= 2*(n-1);
        if(t < n) return t+1;
        return 2*n-t-1;        
    }
};
