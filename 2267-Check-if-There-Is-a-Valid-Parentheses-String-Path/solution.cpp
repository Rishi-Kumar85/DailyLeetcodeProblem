class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 == 1) {
            return false;
        }

        // If starting character is ')', impossible
        if (grid[0][0] == ')') {
            return false;
        }

        int maxBalance = m + n;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(maxBalance + 1, false)
            )
        );

        // Starting cell
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance <= maxBalance; balance++) {

                    if (!dp[i][j][balance]) {
                        continue;
                    }

                    // Move down
                    if (i + 1 < m) {
                        int newBalance = balance;

                        if (grid[i + 1][j] == '(') {
                            newBalance++;
                        } else {
                            newBalance--;
                        }

                        if (newBalance >= 0 &&
                            newBalance <= maxBalance) {

                            dp[i + 1][j][newBalance] = true;
                        }
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBalance = balance;

                        if (grid[i][j + 1] == '(') {
                            newBalance++;
                        } else {
                            newBalance--;
                        }

                        if (newBalance >= 0 &&
                            newBalance <= maxBalance) {

                            dp[i][j + 1][newBalance] = true;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};