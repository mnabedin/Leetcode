/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(const TreeNode* node, const int current_sum) {
        if (node == nullptr) return 0;
        const int new_sum = current_sum * 10 + node -> val;
        if (node -> left == nullptr && node -> right == nullptr) 
            return new_sum;
        return dfs(node -> left, new_sum) + dfs(node -> right, new_sum);
    }

    int sumNumbers(TreeNode* root) {
       return dfs(root, 0); 
    }
};

