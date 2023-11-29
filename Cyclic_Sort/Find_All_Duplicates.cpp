#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            int j = nums[i] - 1;
            if (nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i++;
            }
        }
        vector<int> result;
        for (i = 0; i < n; ++i) {
            int j = i + 1;
            if (nums[i] != j) result.push_back(nums[i]);
        }
        return result;
    }
};

