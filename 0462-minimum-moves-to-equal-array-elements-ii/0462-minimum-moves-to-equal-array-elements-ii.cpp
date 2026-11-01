class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // The median minimizes the sum of absolute differences.

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2]; // Any target between median gives
                                            // the same minimum total cost.

        int ans = 0;

        for (int x : nums) {
            ans += abs(x - median);
        }

        return ans;
    }
};