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
    bool dfs(const TreeNode* node, const int target_sum) {
        if (node == nullptr) return false;
        if (node -> left == nullptr && node -> right == nullptr && node -> val == target_sum)
            return true;
        const int to_find = target_sum - node -> val;
        return dfs(node -> left, to_find) || dfs(node -> right, to_find);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};

