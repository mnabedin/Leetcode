class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string res = "";
        for(const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;
        int i = 0;
        int n = str.size();
        int j, len;
        string word;
        while(i < n) {
            j = i;
            while(str[j] != '#') j++;
            len = stoi(str.substr(i, j - i));
            word = str.substr(j + 1, len);
            res.push_back(word);
            i = j + len + 1;
        }
        return res;
    }
};