#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), target = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    res.push_back(temp);
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

