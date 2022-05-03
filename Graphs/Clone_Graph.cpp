class Solution {
public:
	unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (!node) 
            return nullptr;
    	mp = {};
        return dfs(node);
    }

    Node* dfs(Node* node) {
    	if (mp.find(node) != mp.end())
    		return mp[node];
    	Node* new_node = new Node(node -> val);
    	mp[node] = new_node;
    	for (auto nei : node -> neighbors) {
    		mp[node] -> neighbors.push_back(dfs(nei));
    	}
    	return new_node;
    }
};
