class Solution {
public:

    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {

        Node res;

        // Product of the whole combined segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside the left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }

        // Prefixes which contain:
        // entire left segment + a prefix of right
        for (int r = 0; r < k; r++) {

            int newRemainder =
                (left.prod * r) % k;

            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {

            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] =
            mergeNode(tree[node * 2],
                      tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {

            // Clear old information
            for (int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            int rem = value % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(node * 2,
                   l, mid,
                   index, value);
        }
        else {
            update(node * 2 + 1,
                   mid + 1, r,
                   index, value);
        }

        tree[node] =
            mergeNode(tree[node * 2],
                      tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Complete segment is inside query
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(node * 2,
                         l, mid,
                         ql, qr);
        }

        // Completely in right
        if (ql > mid) {
            return query(node * 2 + 1,
                         mid + 1, r,
                         ql, qr);
        }

        // Query overlaps both sides
        Node left =
            query(node * 2,
                  l, mid,
                  ql, qr);

        Node right =
            query(node * 2 + 1,
                  mid + 1, r,
                  ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        k = K;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(1, 0, n - 1, nums);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1,
                   index, value);

            // Query [start, n-1]
            Node res =
                query(1, 0, n - 1,
                      start, n - 1);

            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};