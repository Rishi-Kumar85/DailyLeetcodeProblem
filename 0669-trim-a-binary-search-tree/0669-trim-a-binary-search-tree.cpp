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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val < low) { // If the current node's value is less than low,
                               // trim the right subtree
            return trimBST(root->right, low, high);
        }

        if (root->val > high) { // If the current node's value is greater than
                                // high, trim the left subtree
            return trimBST(root->left, low, high);
        }

        root->left =
            trimBST(root->left, low, high); // Recursively trim the left subtree
        root->right = trimBST(root->right, low,
                              high); // Recursively trim the right subtree

        return root;
    }
};