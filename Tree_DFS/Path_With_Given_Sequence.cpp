#include <vector>

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


bool dfs(const TreeNode* node, const int pointer, const vector<int>& sequence) {
    if (node == nullptr || pointer >= sequence.size() ||
            sequence[pointer] != node->val) {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr &&
            node->val == sequence[pointer]) {
        return true;
    }

    return dfs(node->left, pointer + 1, sequence) || dfs(node->right,
            pointer + 1, sequence);
}

static bool find_path(const TreeNode* root, const vector<int>& sequence) {
    if (!root) return sequence.empty();
    return dfs(root, 0, sequence);
}

