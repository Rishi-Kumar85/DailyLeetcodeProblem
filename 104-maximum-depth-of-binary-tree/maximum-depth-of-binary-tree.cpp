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

    int maxDepth(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return 0;
        }

        // Find depth of left subtree
        int left = maxDepth(root->left);

        // Find depth of right subtree
        int right = maxDepth(root->right);

        // Current node adds 1
        return 1 + max(left, right);
    }
};