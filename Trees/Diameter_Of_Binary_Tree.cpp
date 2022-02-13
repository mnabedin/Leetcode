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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        findHeight(root, depth);
        return depth;
    }
    
    int findHeight(TreeNode* node, int& depth) {
        if(!node) return 0;
        int left = findHeight(node -> left, depth);
        int right = findHeight(node -> right, depth);
        depth = max(depth, left + right);
        return max(left, right) + 1;
    }
    
};