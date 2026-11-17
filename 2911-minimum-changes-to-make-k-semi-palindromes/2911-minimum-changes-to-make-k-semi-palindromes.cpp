
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;

        // Part 1: Find proper divisors of every length.
        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d < n; d++) {
            for (int len = 2 * d; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        // Part 2: Precompute substring costs.
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                for (int d : divisors[len]) {
                    int changes = 0;

                    // Compare mirrored characters in each group.
                    for (int offset = 0; offset < d; offset++) {
                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r]) {
                                changes++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Part 3: DP for partitioning the string.
        // dp[i][p] = minimum cost to divide s[i...] into p pieces.
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int p = 1; p <= k; p++) {

                // Choose the ending index of the first piece.
                for (int j = i + 1; j < n; j++) {

                    if (dp[j + 1][p - 1] == INF) {
                        continue;
                    }

                    int total = cost[i][j] + dp[j + 1][p - 1];

                    dp[i][p] = min(dp[i][p], total);
                }
            }
        }

        return dp[0][k];
    }
};
