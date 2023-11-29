#include <algorithm>
#include <limits>

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
    int dfs(const TreeNode* node, int& max_sum) {
        if (!node) return 0;

        int left = dfs(node->left, max_sum);
        int right = dfs(node->right, max_sum);
       
        left = max(left, 0);
        right = max(right, 0);

        max_sum = max(max_sum, left + right + node->val);
        
        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int max_path_sum = numeric_limits<int>::min();
        dfs(root, max_path_sum);
        return max_path_sum;
    }
};

