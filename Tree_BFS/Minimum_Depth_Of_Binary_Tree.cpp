#include <queue>

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

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            depth++;
            int level_size = queue.size();
            for (int i = 0; i < level_size; ++i) {
                const TreeNode* node = queue.front();
                queue.pop();
                if (!node -> left && !node -> right) return depth;
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
        }
        return depth;
    }
};

