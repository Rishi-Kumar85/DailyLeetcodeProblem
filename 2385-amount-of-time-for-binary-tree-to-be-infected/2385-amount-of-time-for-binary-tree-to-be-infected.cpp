class Solution {
public:
    TreeNode* startNode = NULL;

    void find(TreeNode* root, int start) {
        if (!root)
            return;
        if (root->val == start) {
            startNode = root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }

    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!root)
            return;
        if (root->left) {
            parentMap[root->left] = root;
            markParents(root->left, parentMap);
        }
        if (root->right) {
            parentMap[root->right] = root;
            markParents(root->right, parentMap);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root)
            return 0;

        // DFS to find start node
        find(root, start);

        // DFS to mark parentMap
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParents(root, parentMap);

        // BFS to calculate the time taken for infection
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
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