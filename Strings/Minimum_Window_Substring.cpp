class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() == 0) return "";
        int n = s.size(), res_len = INT_MAX, start = 0, loc = -1, have = 0;
        unordered_map<char, int> t_map, table;
        for(char c : t) t_map[c]++;
        int need = t_map.size();
        string res = "";
        for(int end = 0; end < n; end++) {
            char c_end = s[end];
            table[c_end]++;
            if(t_map.find(c_end) != t_map.end() && table[c_end] == t_map[c_end]) have++;
            while(have == need) {
                if(end - start + 1 < res_len) {
                    res_len = end - start + 1;
                    loc = start;
                }
                char c_start = s[start++];
                table[c_start]--;
                if(t_map.find(c_start) != t_map.end() && table[c_start] < t_map[c_start]) have--;
            }
        }
        return res_len != INT_MAX ? s.substr(loc, res_len) : "";
    }
};