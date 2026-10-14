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

    TreeNode* build(vector<int>& pre,int preStart,int preEnd,vector<int>& post,int postStart,int postEnd){
        if(preStart > preEnd || postStart < postEnd) return NULL;
         TreeNode* root = new TreeNode(pre[preStart]);

         if(preStart == preEnd) return root; // Leaf node

         int i = postStart;
         while(i>=postEnd){
            if(post[i]==pre[preStart+1]) break;
            i--;
         }

         int leftSize=i-postEnd+1;
         int rightSize=postStart-i-1;

         root->left = build(pre,preStart+1,preStart+leftSize,post,i,postEnd);
         root->right = build(pre,preStart+leftSize+1,preEnd,post,postStart-1,i+1);

         return root;

    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(n==0) return NULL;
        return build(pre,0,n-1,post,n-1,0);
    }
};