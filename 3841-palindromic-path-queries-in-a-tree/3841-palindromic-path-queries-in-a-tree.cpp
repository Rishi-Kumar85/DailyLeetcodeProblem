
class Fenwick {
private:
    int n;
    vector<int> bit;

public:
    Fenwick(int size) : n(size), bit(size + 1, 0) {}

    // XOR difference update at a single Euler position.
    void add(int index, int value) {
        for (int i = index + 1; i <= n; i += i & -i) {
            bit[i] ^= value;
        }
    }

    // XOR of difference values from position 0 to index.
    int query(int index) {
        int result = 0;

        for (int i = index + 1; i > 0; i -= i & -i) {
            result ^= bit[i];
        }

        return result;
    }

    // Apply XOR value to every position in [left, right].
    void rangeXor(int left, int right, int value) {
        add(left, value);

        if (right + 1 < n) {
            add(right + 1, value);
        }
    }
};

class Solution {
private:
    int n, LOG;
    vector<vector<int>> graph;
    vector<vector<int>> up;
    vector<int> depth, tin, tout, parent;
    Fenwick* fenwick = nullptr;

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    // Find the Lowest Common Ancestor using binary lifting.
    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

    // Build Euler entry positions and subtree intervals iteratively.
    void buildEuler() {
        vector<int> order;
        order.reserve(n);

        vector<int> subtreeSize(n, 1);
        vector<bool> visited(n, false);
        stack<int> st;

        st.push(0);
        parent[0] = 0;
        visited[0] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = (int)order.size();
            order.push_back(u);

            for (int v : graph[u]) {
                if (visited[v]) {
                    continue;
                }

                visited[v] = true;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }

        // Accumulate subtree sizes from children to parents.
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            subtreeSize[parent[u]] += subtreeSize[u];
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + subtreeSize[u] - 1;
        }

        // Build binary-lifting ancestor table.
        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        graph.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        parent.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        buildEuler();

        Fenwick fw(n);
        fenwick = &fw;

        // Each node's character contributes to its entire subtree.
        // Therefore each point stores its current root-to-node XOR.
        for (int u = 0; u < n; u++) {
            fenwick->rangeXor(
                tin[u], tout[u], charMask(s[u])
            );
        }

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int delta = charMask(s[u]) ^ charMask(c);

                if (delta != 0) {
                    fenwick->rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int ancestor = lca(u, v);

                int maskU = fenwick->query(tin[u]);
                int maskV = fenwick->query(tin[v]);

                // The LCA appears in both root prefixes,
                // so add its character back once.
                int pathMask =
                    maskU ^ maskV ^ charMask(s[ancestor]);

                // True if zero or one bits are set.
                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        fenwick = nullptr;
        return answer;
    }
};
