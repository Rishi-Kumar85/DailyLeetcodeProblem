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
    TreeNode* inorderSuccessor(TreeNode* root) {
        TreeNode* successor = root->right; // go right once
        while (successor->left != NULL) {  // then go left as far as possible
            successor = successor->left;
        }
        return successor;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (key < root->val) { // If the key to be deleted is smaller than the
                               // root's value, then it lies in left subtree
            root->left = deleteNode(root->left, key);
        } else if (key >
                   root->val) { // If the key to be deleted is greater than the
                                // root's value, then it lies in right subtree
            root->right = deleteNode(root->right, key);
        } else { // If key is same as root's value, then this is the node to be
                 // deleted
            if (root->left == NULL) { // Node with only one child or no child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in
            // the right subtree)
            TreeNode* ios = inorderSuccessor(root);
            // Copy the inorder successor's content to this node
            root->val = ios->val;
            // Delete the inorder successor
            root->right = deleteNode(root->right, ios->val);
        }
        return root;
    }
};