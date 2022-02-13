class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == k) return s.size();
        unordered_map<char, int> mp;
        int res = 0, start = 0, max_freq = INT_MIN;
        for(int end = 0; end < s.size(); end++) {
            char char_end = s[end];
            mp[char_end]++;
            max_freq = max(max_freq, mp[char_end]);
            while(end - start + 1 - max_freq > k) {
                char char_start = s[start];
                mp[char_start]--;
                start++;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};