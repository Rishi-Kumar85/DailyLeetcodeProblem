
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 1;

        int prev = INT_MIN;

        int dp0 = 1;
        int dp1 = 1;

        for (int num : nums) {

            if (num == prev) {
                // Increase current number by 1.
                dp1 = dp0 + 1;
            }

            else if (num == prev + 1) {
                // Current number can extend both states.
                dp0++;
                dp1++;
            }

            else if (num == prev + 2) {
                // Increase previous number, then append current.
                dp0 = dp1 + 1;
                dp1 = 1;
            }

            else {
                // Start new sequences.
                dp0 = 1;
                dp1 = 1;
            }

            ans = max({ans, dp0, dp1});

            prev = num;
        }

        return ans;
    }
};
