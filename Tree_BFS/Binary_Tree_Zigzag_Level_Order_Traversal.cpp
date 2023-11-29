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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
        bool left_to_right = true;
        while (!queue.empty()) {
           const int level_size = queue.size();
           vector<int> level(level_size);
           for (int i = 0; i < level_size; ++i) {
               const TreeNode* node = queue.front();
               queue.pop();
               if (left_to_right) {
                   level[i] = node -> val;
               } else {
                   level[level_size - i - 1] = node -> val;
               }
               if (node -> left) queue.push(node -> left);
               if (node -> right) queue.push(node -> right);
           }
           result.push_back(level);
           left_to_right = !left_to_right;
        }
        return result;
    }
};

