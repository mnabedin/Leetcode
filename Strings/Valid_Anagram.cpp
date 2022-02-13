class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if(len1 != len2) return false;
        unordered_map<char, int> mp;
        for(int i = 0; i < len1; i++) {
            mp[s[i]]++;
        }
        for(int j = 0; j < len2; j++) {
            if(mp.find(t[j]) == mp.end()) return false;
            mp[t[j]]--;
        }
        for(pair<char, int> p : mp) {
            if(p.second != 0) return false;
        }
        return true;
    }
};