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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return construct(preorder, inorder, root, 0, preorder.size() - 1);
    }
    
    TreeNode* construct(const vector<int>& preorder, const vector<int>& inorder, int& root, int left, int right) {
        if(left > right) return nullptr;
        int index = left;
        while(inorder[index] != preorder[root]) index++;
        root++;
        TreeNode* node = new TreeNode(inorder[index]);
        node -> left = construct(preorder, inorder, root, left, index - 1);
        node -> right = construct(preorder, inorder, root, index + 1, right);
        return node;
    }
    
};