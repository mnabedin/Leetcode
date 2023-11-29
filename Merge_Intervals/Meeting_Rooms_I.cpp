#include <vector>

using namespace std;

/**
 * Definition of Interval:
 */
class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end(), [](const Interval& x,
                    const Interval& y) {
                return x.start < y.start;
                });
        int last_end_time = -1;
        for (const auto& interval : intervals) {
            if (last_end_time > interval.start) return false;
            last_end_time = max(last_end_time, interval.end);
        }
        return true;
    }
};

