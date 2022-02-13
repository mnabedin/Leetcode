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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        return findPath(root, targetSum, path);
    }
    
    int findPath(TreeNode* node, int targetSum, vector<int>& path) {
        if(!node) return 0;
        path.push_back(node -> val);
        int count = 0, res = 0;
        for(int i = path.size() - 1; i >= 0; i--) {
            count += path[i];
            if(count == targetSum) res++;
        }
        res += findPath(node -> left, targetSum, path);
        res += findPath(node -> right, targetSum, path);
        path.pop_back();
        return res;
    }
};