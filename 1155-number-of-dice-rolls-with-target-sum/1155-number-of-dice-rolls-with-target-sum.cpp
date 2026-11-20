class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        long long mod = 1e9+7;
        dp[0][0] = 1; // Base case: There's one way to get sum 0 with 0 dice

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int face = 1; face <= k;
                     ++face) { // Each die can show values from 1 to k
                    if (j - face >= 0) {
                        dp[i][j] += dp[i - 1][j - face];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};