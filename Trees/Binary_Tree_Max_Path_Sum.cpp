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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        findMaxPathSum(root, res);
        return res;
    }
    
    int findMaxPathSum(TreeNode* node, int& path) {
       if(!node) return 0;
       int left = max(findMaxPathSum(node -> left, path), 0);
       int right = max(findMaxPathSum(node -> right, path), 0);
       path = max(path, node -> val + left + right);
       return max(left, right) + node -> val;
    }
    
};