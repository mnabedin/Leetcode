bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), last_end_time = INT_MIN, res = 0;
        if(n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            if(start < last_end_time) {
                res++;
            } else {
                last_end_time = intervals[i][1];
            }
        }
        return res;
    }
};