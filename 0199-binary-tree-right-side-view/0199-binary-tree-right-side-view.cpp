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
    int numOfLevels(TreeNode* root){
    if(!root) return 0;
    int leftLevel = numOfLevels(root->left);
    int rightLevel = numOfLevels(root->right);
    return max(leftLevel,rightLevel) + 1;
}

void nthLevel(TreeNode* root,int curr,int level,vector<int>& ans){
    if(!root) return;
    if(curr == level){
        ans[level] = root->val;
        return;
    }
    nthLevel(root->left,curr+1,level,ans);
    nthLevel(root->right,curr+1,level,ans);
}



void levelOrder(TreeNode* root, vector<int>& ans){
    int n = ans.size();
    for(int i=0;i<n;i++){
        nthLevel(root,0,i,ans);
    }
}

vector<int> rightSideView(TreeNode* root) {
   vector<int> ans(numOfLevels(root),0);
   levelOrder(root,ans);
   return ans;
}
};