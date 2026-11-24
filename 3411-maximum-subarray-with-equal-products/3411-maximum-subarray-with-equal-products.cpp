#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        // Calculate LCM of the entire array
        long long allLcm = 1;
        int maxNum = 0;

        for (int x : nums) {
            allLcm = allLcm / gcd(allLcm, (long long)x) * x;
            maxNum = max(maxNum, x);
        }

        // Safe upper bound for GCD * LCM
        long long limit = allLcm * maxNum;

        int ans = 0;

        // Choose starting index
        for (int i = 0; i < n; i++) {

            long long product = 1;
            int currentGcd = 0;
            long long currentLcm = 1;

            // Extend the subarray
            for (int j = i; j < n; j++) {
                int x = nums[j];

                product *= x;

                currentGcd = gcd(currentGcd, x);

                currentLcm = currentLcm /
                    gcd(currentLcm, (long long)x) * x;

                // Check product-equivalent condition
                if (product == currentGcd * currentLcm) {
                    ans = max(ans, j - i + 1);
                }

                // Stop if product becomes too large
                if (product > limit) {
                    break;
                }
            }
        }

        return ans;
    }
};