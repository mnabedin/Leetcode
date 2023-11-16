#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum < target) {
                left++;
            } else if (current_sum > target) {
                right--;
            } else {
                return vector<int>{left + 1, right + 1};
            }
        }
        return {};
    }
};

