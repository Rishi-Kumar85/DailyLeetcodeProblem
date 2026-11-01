class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D array to store the number of unique paths to each cell
        int dp[m][n];

        // Initialize the first row and first column to 1
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1; // There is only one way to reach any cell in the
                          // first column (by moving down)
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1; // There is only one way to reach any cell in the
                          // first row (by moving right)
        }

        // Fill the rest of the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The bottom-right corner will have the total number of unique paths
        return dp[m - 1][n - 1];
    }
};