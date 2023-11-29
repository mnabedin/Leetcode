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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            const int level_size = queue.size();
            double level_sum = 0.0;
            for (int i = 0; i < level_size; ++i) {
                const TreeNode* node = queue.front();
                queue.pop();
                level_sum += node -> val;
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
            const double level_average = level_sum / level_size;
            result.push_back(level_average);
        }
        return result;
    }
};

