class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int maximum = INT_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > maximum) {
                maximum = nums[i];
                count = 1;
                ans = 1;
            }
            else if (nums[i] == maximum) {
                count++;
                ans = max(ans, count);
            }
            else {
                count = 0;
            }
        }

        return ans;
    }
};