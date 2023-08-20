/*
Problem Statement: https://leetcode.com/problems/merge-intervals/description/?envType=list&envId=oqv95d22

APPROACH: GREEDY
    - We need to find maximum no. OVERLAPPING intervals
    - So we sort them by their starting time.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &v1, auto &v2){
            return v1[0] < v2[0];
        });

        vector<vector<int>> answer;
        int a = intervals[0][0], b = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if(x <= b) {
                b = max(y, b);
            } else {
                answer.push_back({a, b});
                a = x, b = y;
            }
        }
        answer.push_back({a, b});
        return answer;
    }
};
