class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        // dp[r] = number of subarrays ending at
        // previous index whose product % k == r
        vector<long long> dp(k, 0);

        // ans[r] = total number of subarrays
        // whose product % k == r
        vector<long long> ans(k, 0);

        for (int x : nums) {

            vector<long long> newdp(k, 0);

            // Start a new subarray [x]
            int remainder = x % k;
            newdp[remainder]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {

                if (dp[r] == 0)
                    continue;

                int newRemainder = (r * (x % k)) % k;

                newdp[newRemainder] += dp[r];
            }

            // Add current subarrays to final answer
            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            // Current subarrays become previous
            dp = newdp;
        }

        return ans;
    }
};