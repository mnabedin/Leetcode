#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int window_start = 0, window_prod = 1, n = nums.size();
        int res = 0;
        int window_len = 0;
        for (int window_end = 0; window_end < n; ++window_end) {
            window_prod *= nums[window_end];
            while (window_start <= window_end && window_prod >= k) {
                window_prod /= nums[window_start++];
            }
            window_len = window_end - window_start + 1;
            res += window_len;
        }
        return res;
    }
};

