class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int len = right - left + 1;

                // Check if a valid subarray existed before this one
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store the best subarray ending at or before right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {

                // No new valid subarray
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};