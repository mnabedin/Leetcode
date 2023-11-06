#include <vector>

using namespace std;

int maximumSumSubarraySizeK(vector<int> nums, int k) {
    int maximum_sum, window_start = 0;
    int window_sum = 0;
    for (int window_end = 0; window_end < nums.size(); window_end++) {
        window_sum += nums[window_end];
        if (window_end >= k - 1) {
            maximum_sum = max(maximum_sum, window_sum);
            window_sum -= nums[window_start++];
        }
    }

    return maximum_sum;
}

