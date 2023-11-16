#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next_non_duplicate = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[next_non_duplicate - 1] != nums[i]) {
                nums[next_non_duplicate++] = nums[i];
            }
        }
        return next_non_duplicate;
    }
};

