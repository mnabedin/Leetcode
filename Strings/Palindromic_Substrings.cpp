class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) n;
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += expand(s, i, i);
            res += expand(s, i, i + 1);
        }
        return res;
    }
    
    int expand(const string& s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};