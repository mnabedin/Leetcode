/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    bool check(TreeNode* node, long lower, long higher) {
        if(!node) return true;
        long node_val = node -> val;
        if(node_val <= lower || node_val >= higher) return false;
        return check(node -> left, lower, node_val) && check(node -> right, node_val, higher);
    }
    
};