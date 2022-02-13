class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end;
    TrieNode() {
        children = {};
        end = false;
    }
    
};


class Trie {
public:
    
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(const char& c : word) {
            if(curr -> children.find(c) == curr -> children.end())
                curr -> children[c] = new TrieNode();
            curr = curr -> children[c];
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(const char& c : word) {
            if(curr -> children.find(c) == curr -> children.end())
                return false;
            curr = curr -> children[c];
        }
        return curr -> end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(const char& c : prefix) {
            if(curr -> children.find(c) == curr -> children.end())
                return false;
            curr = curr -> children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */