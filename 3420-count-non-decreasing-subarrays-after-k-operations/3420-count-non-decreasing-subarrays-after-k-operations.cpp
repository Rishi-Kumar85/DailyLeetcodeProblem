class Solution {
public:
    long long countNonDecreasingSubarrays(
        vector<int>& nums, int k) {

        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        // Stores indices of groups
        deque<int> dq;

        // Right boundary of the window
        int j = n - 1;

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];

            // Merge groups having smaller heights
            while (!dq.empty() &&
                   nums[dq.back()] < num) {

                int l = dq.back();
                dq.pop_back();

                int r = dq.empty() ? j + 1 : dq.back();

                // Increase the entire group to num
                cost += 1LL * (r - l) *
                        (num - nums[l]);
            }

            // Insert the new group
            dq.push_back(i);

            // Shrink window if operations exceed k
            while (cost > k) {

                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j) {
                    dq.pop_front();
                }

                j--;
            }

            // Count all valid subarrays starting at i
            ans += j - i + 1;
        }

        return ans;
    }
};