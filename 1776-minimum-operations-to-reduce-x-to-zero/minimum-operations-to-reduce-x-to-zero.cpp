class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // Calculate total sum
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // We cannot remove elements whose sum is x
        if (totalSum < x) {
            return -1;
        }

        // We want to keep a subarray
        // whose sum is totalSum - x
        int target = totalSum - x;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Window sum is too large
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with required sum
            if (sum == target) {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }
        }

        // No valid subarray
        if (maxLen == -1) {
            return -1;
        }

        // Everything outside the longest subarray
        // has to be removed
        return n - maxLen;
    }
};