class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        deque<TreeNode*> dq;
        dq.push_back(root);
        bool reverse = false;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                if (!reverse) {
                    TreeNode* node = dq.front(); dq.pop_front();
                    level.push_back(node->val);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    TreeNode* node = dq.back(); dq.pop_back();
                    level.push_back(node->val);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }

            res.push_back(level);
            reverse = !reverse;
        }

        return res;
    }
};