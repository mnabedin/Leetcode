#include <algorithm>

using namespace std;
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


int dfs(const TreeNode* node, int& tree_diameter) {
    if (!node) return 0;
    
    const int left_height = dfs(node->left, tree_diameter);
    const int right_height = dfs(node->right, tree_diameter);

    tree_diameter = max(tree_diameter, left_height + right_height + 1);

    const int height = max(left_height, right_height) + 1;
    return height;
}

static int find_diameter(const TreeNode* root) {
    int tree_diameter = 0;
    dfs(root, tree_diameter);
    return tree_diameter;
}

