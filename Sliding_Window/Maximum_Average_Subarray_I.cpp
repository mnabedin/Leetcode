#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int window_start = 0;
        double res = INT_MIN; 
        int n = nums.size();
        double window_avg, window_sum = 0;
        for (int window_end = 0; window_end < n; window_end++) {
            window_sum += nums[window_end];
            if (window_end >= k - 1) {
                double curr_avg = window_sum / k;
                res = max(res, curr_avg);
                window_sum -= nums[window_start++];
            }
        }
        return res;
    }
};
