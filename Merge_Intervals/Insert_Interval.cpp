#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {{newInterval}};        
        vector<vector<int>> result;
        int i = 0;
        for (const auto& current_interval : intervals) {
            if (current_interval[1] < newInterval[0]) {
                result.push_back(current_interval);
            } else if (newInterval[1] < current_interval[0]) {
                result.push_back(newInterval);
                int n = intervals.size();
                while (i < n) {
                    result.push_back(intervals[i++]);
                }
                return result;
            } else {
                newInterval[0] = min(newInterval[0], current_interval[0]);
                newInterval[1] = max(newInterval[1], current_interval[1]);
            }
            i++;
        }
        result.push_back(newInterval);
        return result;
    }
};

