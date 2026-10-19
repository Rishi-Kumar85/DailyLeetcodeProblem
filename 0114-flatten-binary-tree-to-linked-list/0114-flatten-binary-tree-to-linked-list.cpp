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
    void flatten(TreeNode* root) {
         if(!root) return;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    flatten(l);
    flatten(r);
    root->left=NULL;
    root->right = l;
    TreeNode* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    curr->right = r;
    }
};