class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size() == 0) return res;
        unordered_map<string, vector<string>> mp;
        string sorted_word;
        for(const string& s : strs) {
            sorted_word = s;
            sort(sorted_word.begin(), sorted_word.end());
            mp[sorted_word].push_back(s);
        }
        for(auto p : mp) {
            res.push_back(p.second);
        }
        return res;
    }
};