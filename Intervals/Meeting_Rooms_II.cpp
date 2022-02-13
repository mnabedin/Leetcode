/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        map<int, int> mp;
        for(const Interval& interval : intervals) {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        int temp = 0, res = 0;
        for(const pair<int, int>& kv : mp) {
            temp += kv.second;
            res = max(res, temp);
        }
        return res;
    }
};