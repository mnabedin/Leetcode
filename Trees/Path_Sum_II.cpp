/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        findPath(root, targetSum, res, path);
        return res;
    }
    
    void findPath(TreeNode* node, int targetSum, vector<vector<int>>& res, vector<int>& path) {
        if(!node) return;
        path.push_back(node -> val);
        if(!node -> left && !node -> right && node -> val == targetSum) {
            res.push_back(path);
        } else {
            findPath(node -> left, targetSum - node -> val, res, path);
            findPath(node -> right, targetSum - node -> val, res, path);
        }
        path.pop_back();
    }
};