#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window_len = 0, window_start = 0, n = s.size();
        unordered_map<char, int> map;
        for (int window_end = 0; window_end < n; ++window_end) {
            const char char_at_end = s[window_end];
            map[char_at_end]++;
            while (map[char_at_end] > 1) {
                const char char_at_start = s[window_start++];
                map[char_at_start]--;
                if (map[char_at_start] == 0) map.erase(char_at_start);
            }
            window_len = max(window_len, window_end - window_start + 1);
        }
        return window_len;
    }
};

