/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        mp = {};
        return dfs(node);
    }
    
    
    Node* dfs(Node* old_node) {
        if(mp.find(old_node) != mp.end())
            return mp[old_node];
        mp[old_node] = new Node(old_node -> val);
        for(auto nei : old_node -> neighbors)
            mp[old_node] -> neighbors.push_back(dfs(nei));
        return mp[old_node];
    } 
};