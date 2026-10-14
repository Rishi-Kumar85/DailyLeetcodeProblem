/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
   int countFrom(TreeNode* node, long long remaining) {
    if (!node) return 0;

    return (node->val == remaining)
        + countFrom(node->left, remaining - node->val)
        + countFrom(node->right, remaining - node->val);
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;

    return countFrom(root, targetSum)
        + pathSum(root->left, targetSum)
        + pathSum(root->right, targetSum);
}
};