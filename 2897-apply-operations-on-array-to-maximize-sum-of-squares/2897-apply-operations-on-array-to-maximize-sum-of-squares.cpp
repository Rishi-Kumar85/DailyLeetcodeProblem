class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        int count[32] = {};

        // Step 1: Count set bits
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1LL << bit)) {
                    count[bit]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (count[bit] > 0) {
                    x |= (1LL << bit);
                    count[bit]--;
                }
            }

            // Step 3: Add the square
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};