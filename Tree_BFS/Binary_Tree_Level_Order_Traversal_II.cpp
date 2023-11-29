#include <queue>
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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> level;
            const int level_size = queue.size();
            for (int i = 0; i < level_size; ++i) {
                const TreeNode* node = queue.front();
                queue.pop();
                level.push_back(node -> val);
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
            result.push_back(level);
        } 
        reverse(result.begin(), result.end());
        return result;
    }
};

