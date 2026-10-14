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
   void helper(TreeNode* node, int targetSum, vector<int> currentPath, vector<vector<int>>& result) {
    if (!node) return;

    currentPath.push_back(node->val);
    targetSum -= node->val;

    // If it's a leaf node and the target sum is reached
    if (!node->left && !node->right && targetSum == 0) {
        result.push_back(currentPath);
    } else {
        helper(node->left, targetSum, currentPath, result);
        helper(node->right, targetSum, currentPath, result);
    }
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    helper(root, targetSum, {}, result);
    return result;
}
};