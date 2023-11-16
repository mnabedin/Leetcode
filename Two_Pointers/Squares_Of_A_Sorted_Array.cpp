#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;       
        int left = 0, right = n - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                ans.push_back(nums[right] * nums[right]);
                right--;
            } else {
                ans.push_back(nums[left] * nums[left]);
                left++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

