class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if (n == 0 || k <= 0)
            return result;
        vector<int> nextGreaterIndex(n, n); // Initialize with n, which means no
                                            // greater element to the right
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                nextGreaterIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        int j = 0; // Pointer to the maximum element in the current window
        for (int i = 0; i <= n - k; i++) {
            if (j < i)
                j = i; // Move j to the start of the window if it's out of
                       // bounds
            while (
                nextGreaterIndex[j] <
                i + k) { // Move j to the next greater element within the window
                j = nextGreaterIndex[j];
            }
            result.push_back(nums[j]); // The maximum in the current window
        }
        return result;
    }
};