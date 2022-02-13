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
 bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start;
 }

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        if(n<=1) return true;
        sort(intervals.begin(), intervals.end(), comp);
        int last = INT_MIN;
        for(Interval i : intervals) {
            if(i.start < last) return false;
            last = i.end;
        }
        return true;
    }
};