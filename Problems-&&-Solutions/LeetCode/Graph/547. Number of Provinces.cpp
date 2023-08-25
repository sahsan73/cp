/*
Problem Statement: https://leetcode.com/problems/number-of-provinces/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DSU
*/
class Solution {
private:
    int p[200], r[200];

    int find(int x) {
        return x^p[x] ? p[x]=find(p[x]) : x;
    }

    bool join(int x, int y) {
        if((x=find(x)) == (y=find(y)))
            return 0;
        if(r[x] < r[y])
            swap(x, y);
        p[y] = x;
        if(r[x] == r[y])
            ++r[x];
        return 1;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = (int)isConnected.size();
        iota(p, p+n, 0);
        fill(r, r+n, 0);

        int cnt = n;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(isConnected[i][j]==1 && join(i, j))
                    --cnt;
            }
        }
        return cnt;
    }
};
