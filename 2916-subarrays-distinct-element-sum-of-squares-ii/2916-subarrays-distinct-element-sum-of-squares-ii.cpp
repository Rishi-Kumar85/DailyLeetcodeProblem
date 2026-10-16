class Solution {
private:
    static const int MOD = 1'000'000'007;

    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    // Increase every value in this segment by val.
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long v = val % MOD;
        long long oldSum = tree[node].sum;

        // (x + val)^2 = x^2 + 2*val*x + val^2
        tree[node].sqSum =
            (tree[node].sqSum
             + 2LL * v % MOD * oldSum % MOD
             + v * v % MOD * len % MOD) % MOD;

        tree[node].sum =
            (oldSum + v * len) % MOD;

        tree[node].lazy += val;
    }

    // Pass pending updates to the children.
    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    // Combine the results from both children.
    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum
             + tree[node * 2 + 1].sum) % MOD;

        tree[node].sqSum =
            (tree[node * 2].sqSum
             + tree[node * 2 + 1].sqSum) % MOD;
    }

    // Add val to every position in [ql, qr].
    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr, val);
        }

        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r,
                   ql, qr, val);
        }

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node{});

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = 0;

            // Find the previous occurrence.
            if (last.count(nums[i])) {
                left = last[nums[i]] + 1;
            }

            // Distinct counts increase for starts in [left, i].
            update(1, 0, n - 1, left, i, 1);

            // Sum of squares for all subarrays ending at i.
            ans = (ans + tree[1].sqSum) % MOD;

            // Remember the current occurrence.
            last[nums[i]] = i;
        }

        return static_cast<int>(ans);
    }
};