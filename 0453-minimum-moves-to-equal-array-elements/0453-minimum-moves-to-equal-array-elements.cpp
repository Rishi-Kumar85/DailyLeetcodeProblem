class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Instead of increasing elements, imagine decreasing the larger
        // elements until all elements become equal.
        int mn = *min_element(nums.begin(), nums.end());

        int ans = 0;

        for (int x : nums) {
            ans += x - mn;
        }

        return ans;
    }
};