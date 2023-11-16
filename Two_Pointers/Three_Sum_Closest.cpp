#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum == target) return target;
                int dist_to_target = abs(target - current_sum);
                int res_to_target = abs(target - res);
                if (dist_to_target < res_to_target) res = current_sum;
                if (current_sum < target) { 
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};

