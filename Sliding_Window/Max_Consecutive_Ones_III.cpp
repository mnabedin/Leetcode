#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int window_start = 0, window_len = 0, n = nums.size();       
        int zeroes_in_window = 0;
        for (int window_end = 0; window_end < n; ++window_end) {
            if (nums[window_end] == 0) zeroes_in_window++;
            while (zeroes_in_window > k) {
                if (nums[window_start++] == 0) zeroes_in_window--;
            }
            window_len = max(window_len, window_end - window_start + 1);
        }
        return window_len;
    }
};

