class Solution {
public:
    int numberOfSets(int n, int k) {

        const int MOD = 1000000007;

        // dp[i] = ways for the previous number of segments
        vector<int> dp(n + 1, 1);

        dp[0] = 0;

        // prefix sum of dp
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        }

        for (int j = 1; j <= k; j++) {

            vector<int> new_dp(n + 1, 0);
            vector<int> new_prefix(n + 1, 0);

            for (int i = 2; i <= n; i++) {

                // Don't use this point as the new endpoint
                // OR use it to create/extend a segment
                new_dp[i] =
                    (new_dp[i - 1] + prefix[i - 1]) % MOD;

                // Build prefix sum for the new row
                new_prefix[i] =
                    (new_prefix[i - 1] + new_dp[i]) % MOD;
            }

            dp = new_dp;
            prefix = new_prefix;
        }

        return dp[n];
    }
};