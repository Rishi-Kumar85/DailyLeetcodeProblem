class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        // last[c] stores the value of ans
        // before the previous occurrence of c
        vector<long long> last(26, 0);

        // Includes the empty subsequence
        long long ans = 1;

        for (char c : s) {

            int index = c - 'a';

            long long oldAns = ans;

            // Every old subsequence:
            // 1. doesn't take c
            // 2. takes c
            ans = (2 * ans - last[index] + MOD) % MOD;

            // Remember the state before this occurrence
            last[index] = oldAns;
        }

        // Remove the empty subsequence
        return (ans - 1 + MOD) % MOD;

    }
};