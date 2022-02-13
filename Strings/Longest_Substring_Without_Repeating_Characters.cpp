class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int res = 0, start = 0;
        unordered_set<char> contains;
        for(int end = 0; end < s.size(); end++) {
            char char_end = s[end];
            while(contains.find(char_end) != contains.end()) {
                char char_start = s[start];
                start++;
                contains.erase(char_start);
            }
            contains.insert(char_end);
            res = max(res, end - start + 1);
        }
        return res;
    }
};