class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), local_max = nums[0], global_max = nums[0];
        for(int i = 1; i < n; i++) {
            local_max = max(nums[i], nums[i] + local_max);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};