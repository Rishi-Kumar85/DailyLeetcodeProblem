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
    int heightOfTree(TreeNode* node) {
        if (node == NULL)
            return 0;
        int leftHeight = heightOfTree(node->left);
        int rightHeight = heightOfTree(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    void helper(TreeNode* node, int& maxDia) {
        if (node == NULL)
            return;
        int leftHeight = heightOfTree(node->left);
        int rightHeight = heightOfTree(node->right);
        maxDia = max(maxDia, leftHeight + rightHeight);
        helper(node->left, maxDia);
        helper(node->right, maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};