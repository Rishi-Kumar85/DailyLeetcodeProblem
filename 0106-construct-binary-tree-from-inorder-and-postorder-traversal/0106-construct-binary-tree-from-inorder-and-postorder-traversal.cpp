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
    TreeNode* build(vector<int>& post, int postStart, int postEnd, vector<int>& in, int inStart, int inEnd){
    if(postStart < postEnd || inStart > inEnd) return NULL; // Base case: no elements to construct the tree

    TreeNode* root = new TreeNode(post[postStart]);

    if(postStart == postEnd) return root; // Leaf node

    // Find the index of the root in the inorder array
    int i = inStart;
    while (i <= inEnd) {
        if (in[i] == post[postStart]) break;
        i++;
    }

    int leftSubtreeSize = i - inStart;
    int rightSubtreeSize = inEnd - i;

    // Recursively build the left and right subtrees
    root->left = build(post, postStart - rightSubtreeSize - 1, postEnd, in, inStart, i - 1);
    root->right = build(post, postStart - 1, postStart - rightSubtreeSize, in, i + 1, inEnd);
    return root;
}
   
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        if(n==0) return NULL;
        return build(post,n-1,0,in,0,n-1);
    }
};