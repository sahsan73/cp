/*
Problem Statement: https://leetcode.com/problems/insert-interval/?envType=list&envId=oqv95d22
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
The intervals are already sorted by their starting time, so we can take advantages of this.
    - Find insert position of newInterval in intervals list using binary search.
    - Insert the newInterval into intervals list.
    - Merge the intervals.

COMPLEXITY:
    - TC = O(n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> &newInterval) {
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());

        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval[0], [](auto &v, int mid) {
            return v[0] < mid;
        });
        intervals.insert(it, newInterval);

        vector<vector<int>> answer;
        int a = intervals[0][0], b = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if(x <= b) {
                b = max(b, y);
            } else {
                answer.push_back({a, b});
                a = x, b = y;
            }
        }
        answer.push_back({a, b});
        return answer;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Reusing the concept fo Merge Intervals:
    - Problem: https://leetcode.com/problems/merge-intervals/?envType=list&envId=oqv95d22
    - Solution: https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/LeetCode/Greedy/56.%20Merge%20Intervals.cpp

APPROACH:
    - Push the newInterval in the intervals list.
    - Sort them and then merge them.

COMPLEXITY:
    - TC = O(nlogn)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;
        int a = intervals[0][0], b = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if(x <= b) {
                b = max(b, y);
            } else {
                answer.push_back({a, b});
                a = x, b = y;
            }
        }
        answer.push_back({a, b});
        return answer;
    }
};
