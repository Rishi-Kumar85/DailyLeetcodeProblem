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
    void helper(TreeNode* root, vector<string>& paths, string s) {
        if (root == NULL) {
            return;
        }
        s += to_string(root->val) + "->";
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(
                s.substr(0, s.length() - 2)); // remove the last "->"
            return;
        }
        helper(root->left, paths, s);
        helper(root->right, paths, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> paths;
        helper(root, paths, "");
        return paths;
    }
};