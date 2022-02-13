class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(k == 0) return 0;
        unordered_map<char, int>mp;
        int res = 0, start = 0;
        for(int end = 0; end < s.size(); end++) {
            char char_end = s[end];
            mp[char_end]++;
            while(mp.size() > k) {
                char char_start = s[start];
                mp[char_start]--;
                if(mp[char_start] == 0) mp.erase(char_start);
                start++;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};