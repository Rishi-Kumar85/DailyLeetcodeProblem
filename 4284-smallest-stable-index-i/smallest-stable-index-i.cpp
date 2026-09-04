class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();

        // right[i] = minimum from i to n-1
        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(nums[i], right[i + 1]);
        }

        // Maximum from nums[0] to nums[i]
        int left = 0;

        for (int i = 0; i < n; i++) {

            left = max(left, nums[i]);

            int score = left - right[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};