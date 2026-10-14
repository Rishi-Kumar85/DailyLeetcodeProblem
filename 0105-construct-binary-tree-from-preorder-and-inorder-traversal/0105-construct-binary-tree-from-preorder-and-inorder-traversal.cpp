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
    TreeNode* build(vector<int>& pre, int preStart, int preEnd, vector<int>& in,
                    int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr; // Base case: no elements to construct the tree

        TreeNode* root = new TreeNode(pre[preStart]);

        if (preStart == preEnd)
            return root; // Leaf node

        // Find the index of the root in the inorder array
        int i = inStart;
        while (i <= inEnd) {
            if (in[i] == pre[preStart])
                break;
            i++;
        }

        int leftSubtreeSize = i - inStart;
        int rightSubtreeSize = inEnd - i;

        // Recursively build the left and right subtrees
        root->left = build(pre, preStart + 1, preStart + leftSubtreeSize, in,
                           inStart, i - 1);
        root->right = build(pre, preStart + leftSubtreeSize + 1, preEnd, in,
                            i + 1, inEnd);
        return root;
    }
    // TC: O(n), SC: O(n)
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        if (n == 0)
            return nullptr;
        return build(pre, 0, n - 1, in, 0, n - 1);
    }
};