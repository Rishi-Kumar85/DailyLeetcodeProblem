class Solution {
private:
    static const int MOD = 1'000'000'007;
    vector<vector<long long>> C;

    int dfs(const vector<int>& nums) {
        int n = nums.size();

        // Empty or single-element arrays have one ordering.
        if (n <= 2) {
            return 1;
        }

        int root = nums[0];
        vector<int> left, right;

        // Divide elements into left and right subtrees.
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        // Choose positions for the left-subtree elements.
        long long ways = C[n - 1][left.size()];

        // Multiply by the valid arrangements of both subtrees.
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;

        return static_cast<int>(ways);
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute combinations using Pascal's triangle.
        C.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Subtract the original ordering.
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};