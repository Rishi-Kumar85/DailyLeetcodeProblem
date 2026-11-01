class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting cell has an obstacle, then return 0 as there are no
        // paths.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Create a 2D array to store the number of unique paths to each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; // Starting point

        // Fill the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] =
                (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1)
                    ? 1
                    : 0; // If there's an obstacle, no paths lead to this cell
        }

        // Fill the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] =
                (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1)
                    ? 1
                    : 0; // If there's an obstacle, no paths lead to this cell
        }

        // Fill the rest of the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] =
                        0; // If there's an obstacle, no paths lead to this cell
                }
            }
        }

        // The bottom-right corner will have the total number of unique paths
        return dp[m - 1][n - 1];
    }
};