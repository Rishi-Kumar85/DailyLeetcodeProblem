class Solution {
public:
    void preorder(TreeNode* root, int level, int currentLevel,vector<int>&res) {
        if (root == NULL) {
            return;
        }
        if (currentLevel == level) {
            res.push_back(root->val);
            return;
        }
        preorder(root->left, level, currentLevel + 1,res);
        preorder(root->right, level, currentLevel + 1,res);
    }

    void elementOfNthLevel(TreeNode* root, int level,vector<int>&res) {
        if (root == NULL) {
            return;
        }
        if (level == 1) {
            res.push_back({root->val});
            return;
        }
        preorder(root, level, 1,res);
        return;
    }
    int numberOfLevels(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftLevels = numberOfLevels(root->left);
        int rightLevels = numberOfLevels(root->right);
        return max(leftLevels, rightLevels) + 1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }
        int level = numberOfLevels(root);
        for (int i = 1; i <= level; i++) {
            vector<int>res;
            elementOfNthLevel(root, i,res);
            ans.push_back(res);
        }
        return ans;
    }
};