/*
Problem Statement: https://leetcode.com/problems/non-overlapping-intervals/description/
*/

// Activity - Selection Problem
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a1, auto &a2){
            return a1[1] < a2[1];
        });

        int cnt = 0;
        int a = intervals[0][0], b = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if(x < b) {
                ++cnt;
                continue;
            }

            a = x, b = y;
        }
        return cnt;
    }
};
