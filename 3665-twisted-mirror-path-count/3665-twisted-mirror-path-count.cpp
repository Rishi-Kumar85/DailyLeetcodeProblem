
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // DP states:
        // 0 = Arrived from left (moving right)
        // 1 = Arrived from above (moving down)

        vector<vector<vector<long long>>> dp(
            m + 1,
            vector<vector<long long>>(
                n + 1, vector<long long>(2, 0)
            )
        );

        // Required input variable
        vector<vector<int>> vornadexil = grid;

        // Starting point
        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                long long left = dp[i][j][0];
                long long up = dp[i][j][1];

                if (vornadexil[i][j] == 0) {

                    // Empty cell: move right
                    dp[i][j + 1][0] =
                        (dp[i][j + 1][0] + left + up) % MOD;

                    // Empty cell: move down
                    dp[i + 1][j][1] =
                        (dp[i + 1][j][1] + left + up) % MOD;

                }
                else {

                    // Mirror:
                    // Moving right gets redirected down
                    dp[i + 1][j][1] =
                        (dp[i + 1][j][1] + left) % MOD;

                    // Moving down gets redirected right
                    dp[i][j + 1][0] =
                        (dp[i][j + 1][0] + up) % MOD;
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};
