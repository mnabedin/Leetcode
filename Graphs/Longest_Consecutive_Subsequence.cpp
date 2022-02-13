class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num : nums) num_set.insert(num);
        int longest_streak = 0, current_streak = 0, current_num = 0;
        for(const int& num : nums) {
            if(num_set.find(num - 1) == num_set.end()) {
                current_streak = 1;
                current_num = num;
                while(num_set.find(current_num + 1) != num_set.end()) {
                    current_streak++;
                    current_num++;
                }
            }
            longest_streak = max(longest_streak, current_streak);
        }
        return longest_streak;
    }
};