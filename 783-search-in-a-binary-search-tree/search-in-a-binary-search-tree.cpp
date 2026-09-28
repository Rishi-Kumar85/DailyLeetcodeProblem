class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // Tree is empty
        if (root == nullptr) {
            return nullptr;
        }

        // Found the value
        if (root->val == val) {
            return root;
        }

        // Search in left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // Search in right subtree
        return searchBST(root->right, val);
    }
};