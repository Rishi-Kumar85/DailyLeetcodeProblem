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
    void trim(TreeNode* node, int low, int high) {
        if (node == NULL) {
            return;
        }

        // Trim the left subtree
        while (node->left != NULL) {
            if (node->left->val < low) { // If the left child's value is less
                                         // than low, trim the left subtree
                node->left = node->left->right;
            } else if (node->left->val >
                       high) { // If the left child's value is greater than
                               // high, trim the left subtree
                node->left = node->left->left;
            } else {
                break;
            }
        }
        // Trim the right subtree
        while (node->right != NULL) {
            if (node->right->val < low) { // If the right child's value is less
                                          // than low, trim the right subtree
                node->right = node->right->right;
            } else if (node->right->val >
                       high) { // If the right child's value is greater than
                               // high, trim the right subtree
                node->right = node->right->left;
            } else {
                break;
            }
        }
        // Recursively trim the left and right subtrees
        trim(node->left, low, high);
        trim(node->right, low, high);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy, low, high);
        return dummy->left;
    }
};