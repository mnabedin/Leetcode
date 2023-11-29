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
    vector<vector<int>> result;
    vector<int> current_path;
    void dfs(const TreeNode* node, const int target_sum) {
        if (node == nullptr) return;

        current_path.push_back(node -> val);
        if (node -> val == target_sum && node -> left == nullptr
                && node -> right == nullptr) {
           result.push_back(vector<int>(current_path));
        } else {
            const int to_find = target_sum - node -> val;
            dfs(node -> left, to_find);
            dfs(node -> right, to_find);
        }
        current_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       result = {};
       current_path = {};
       dfs(root, targetSum);
       return result;
    }
};

