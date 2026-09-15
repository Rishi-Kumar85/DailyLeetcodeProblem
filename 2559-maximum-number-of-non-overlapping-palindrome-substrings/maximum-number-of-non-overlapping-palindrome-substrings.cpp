class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // palindrome[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> palindrome(
            n, vector<bool>(n, false)
        );

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || palindrome[i + 1][j - 1])) {

                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {

            // Don't take a palindrome ending here
            dp[i + 1] = dp[i];

            for (int j = 0; j <= i; j++) {

                int length = i - j + 1;

                if (length >= k &&
                    palindrome[j][i]) {

                    dp[i + 1] = max(
                        dp[i + 1],
                        dp[j] + 1
                    );
                }
            }
        }

        return dp[n];
    }
};