class Solution {
public:
    bool isValid(string s) {
        if(s.size() <= 1 || s.size() % 2 != 0) return false;
        stack<char> st;
        map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
        char top;
        for(const char& c : s) {
            if(mapping.find(c) != mapping.end()) {
                top = st.empty() ? '#' : st.top();
                if(!st.empty()) st.pop();
                if(mapping[c] != top) return false;
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};