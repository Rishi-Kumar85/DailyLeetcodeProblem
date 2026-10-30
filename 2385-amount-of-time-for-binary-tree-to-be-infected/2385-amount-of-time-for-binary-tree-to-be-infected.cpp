class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (!root)
            return 0;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = nullptr;

        // BFS to build parent map and find the start node
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) {
                startNode = node;
            }

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS to calculate the time taken for infection
        unordered_map<TreeNode*, bool> visited;
        q.push(startNode);
        visited[startNode] = true;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check left child
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                    infected = true;
                }
                // Check right child
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                    infected = true;
                }
                // Check parent
                if (parentMap.find(node) != parentMap.end() &&
                    !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                    infected = true;
                }
            }

            if (infected) {
                time++;
            }
        }

        return time;
    }
};