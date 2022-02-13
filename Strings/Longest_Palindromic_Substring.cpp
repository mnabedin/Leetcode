class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        string res;
        int res_len = 0;
        string partial;
        for(int i = 0; i < n; i++) {
            partial = expand(s, i, i);
            if(partial.size() > res_len) {
                res = partial;
                res_len = partial.size();
            }
            partial = expand(s, i, i + 1);
            if(partial.size() > res_len) {
                res = partial;
                res_len = partial.size();
            }
        }
        return res;
    }
    
    string expand(const string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};