class Solution {
public:
   int numberOfLevels(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftLevels = numberOfLevels(root->left);
    int rightLevels = numberOfLevels(root->right);
    return max(leftLevels, rightLevels) + 1;
}

void preorder(TreeNode* root, int level, int currentLevel, vector<int>& currentLevelNodes) {
    if (root == NULL) {
        return;
    }
    if (currentLevel == level) {
        currentLevelNodes.push_back(root->val);
        return;
    }
    preorder(root->left, level, currentLevel + 1, currentLevelNodes);
    preorder(root->right, level, currentLevel + 1, currentLevelNodes);
}

void elementOfNthLevel(TreeNode* root, int level, vector<int>& currentLevel) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        currentLevel.push_back(root->val);
        return;
    }
   preorder(root, level, 1, currentLevel);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;

    }

    int level = numberOfLevels(root);
    for (int i = 1; i <= level; i++) {
        vector<int> currentLevel;
        elementOfNthLevel(root, i, currentLevel);
        if (i % 2 == 0) {
            reverse(currentLevel.begin(), currentLevel.end());
        }
        result.push_back(currentLevel);
    }
    return result;
}
};