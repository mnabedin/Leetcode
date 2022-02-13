class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_i, min_i, global, x, y;
        max_i = min_i = global = x = y = nums[0];
        for(int i = 1; i < n; i++) {
            x = max({nums[i], nums[i] * max_i, nums[i] * min_i});
            y = min({nums[i], nums[i] * max_i, nums[i] * min_i});
            max_i = x;
            min_i = y;
            global = max(global, max_i);
        }
        return global;
    }
};