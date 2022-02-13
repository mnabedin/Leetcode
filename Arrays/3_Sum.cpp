class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), left, right, total, target = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            left = i + 1;
            right = n - 1;
            while(left < right) {
                total = nums[i] + nums[left] + nums[right];
                if(total < target) left++;
                else if(total > target) right--;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};