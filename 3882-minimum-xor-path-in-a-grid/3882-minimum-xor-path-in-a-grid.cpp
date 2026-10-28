class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MAX_XOR = 1024;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n, vector<bool>(MAX_XOR, false)
            )
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int value = grid[i][j];

                // Reach this cell from above.
                if (i > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ value] = true;
                        }
                    }
                }

                // Reach this cell from the left.
                if (j > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ value] = true;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < MAX_XOR; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};