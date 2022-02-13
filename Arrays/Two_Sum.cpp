class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()) return vector<int>{i, mp[complement]};
            mp[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};