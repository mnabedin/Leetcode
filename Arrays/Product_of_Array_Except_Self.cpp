class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), multiplier = 1;
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++) {
            res[i] *= multiplier;
            multiplier *= nums[i];
        }
        multiplier = 1;
        for(int i = n - 1; i >= 0; i--) {
            res[i] *= multiplier;
            multiplier *= nums[i];
        }
        return res;
    }
};