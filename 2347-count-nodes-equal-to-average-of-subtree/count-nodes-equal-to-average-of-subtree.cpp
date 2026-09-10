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

        int ans = 0;

    pair<int, int> dfs(TreeNode* root) {

        // If there is no node
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        pair<int, int> left = dfs(root->left);

        // Get sum and count from right subtree
        pair<int, int> right = dfs(root->right);

        // Calculate current subtree sum
        int sum = root->val + left.first + right.first;

        // Calculate current subtree node count
        int count = 1 + left.second + right.second;

        // Calculate average using integer division
        int average = sum / count;

        // Check if current node equals average
        if (root->val == average) {
            ans++;
        }

        // Return sum and count to parent
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};