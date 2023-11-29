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
    long dfs(const TreeNode* node, vector<long>& current_path, const long target_sum) {
        if (node == nullptr) return 0;

        current_path.push_back(node->val);
        const long path_size = current_path.size();
        long path_sum = 0;
        long target_count = 0;
        for (long i = path_size - 1; i >= 0; i--) {
            path_sum += current_path[i];
            if (path_sum == target_sum) target_count++;
        }

        target_count += dfs(node->left, current_path, target_sum);
        target_count += dfs(node->right, current_path, target_sum);
        
        current_path.pop_back();
        return target_count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long> current_path;
        return dfs(root, current_path, targetSum); 
    }
};

