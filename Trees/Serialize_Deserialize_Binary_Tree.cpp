/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        return to_string(root -> val) + "," + serialize(root -> left) + "," + serialize(root -> right);
    }
   
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs(data);
    }
    
    TreeNode* dfs(string& data) {
        if(data[0] == 'N') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node -> left = dfs(data);
            node -> right = dfs(data);
            return node;
        }
    }
    
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        return val;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));