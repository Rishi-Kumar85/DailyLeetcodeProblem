#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Build the original tree
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // Stores nodes of each character on the current path
        vector<vector<int>> path(26);

        // Every node initially counts itself
        vector<int> ans(n, 1);

        // {node, isExitEvent}
        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {
            auto [u, exiting] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (!exiting) {
                // Enter node
                path[c].push_back(u);

                // Schedule its exit after its children
                st.push({u, true});

                // Push children in reverse order
                for (int i = (int)children[u].size() - 1;
                     i >= 0; i--) {
                    st.push({children[u][i], false});
                }
            }
            else {
                // Exit node: all children are processed

                int finalParent = parent[u];

                // Second-last node is the nearest
                // ancestor with the same character
                if (path[c].size() > 1) {
                    finalParent = path[c][path[c].size() - 2];
                }

                // Pass this subtree's size to its final parent
                if (finalParent != -1) {
                    ans[finalParent] += ans[u];
                }

                // Backtrack
                path[c].pop_back();
            }
        }

        return ans;
    }
};