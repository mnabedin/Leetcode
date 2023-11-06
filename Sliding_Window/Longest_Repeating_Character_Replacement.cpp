#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int window_len = 0, window_start = 0, n = s.size(), max_freq = 0;     
        unordered_map<char, int> map;
        for (int window_end = 0; window_end < n; ++window_end) {
            const char char_at_end = s[window_end];
            map[char_at_end]++;
            max_freq = max(max_freq, map[char_at_end]);
            while (window_end - window_start + 1 - max_freq > k) {
                const char char_at_start = s[window_start++];
                map[char_at_start]--;
                if (map[char_at_start] == 0) map.erase(char_at_start);
            }
            window_len = max(window_len, window_end - window_start + 1);
        }
        return window_len;
    }
};

