class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end());

        int count = 0;
        int ans = 0;

        for (int x : nums) {
            if (x == maximum) {
                count++;
                ans = max(ans, count);
            } else {
                count = 0;
            }
        }

        return ans;
    }
};