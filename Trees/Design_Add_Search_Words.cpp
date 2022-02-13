class TrieNode {
    public:
    TrieNode* children[26]{};
    bool end;
    TrieNode() {
        end = false;
    }
    
    TrieNode* get(const char& c) {
        return children[c - 'a'];
    }
    
    void add(const char& c) {
        children[c - 'a'] = new TrieNode();
    }
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(const char& c : word) {
            if(!curr -> get(c)) curr -> add(c);
            curr = curr -> get(c);
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
    
    
    bool dfs(int j, TrieNode* node, const string& word) {
        if(!node) return false;
        TrieNode* curr = node;
        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(int k = 0; k < 26; k++) {
                    if(dfs(i + 1, curr -> children[k], word))
                        return true;
                }
                return false;
            } else {
                if(!curr -> get(c)) return false;
                curr = curr -> get(c);
            }
        }
        return curr -> end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */