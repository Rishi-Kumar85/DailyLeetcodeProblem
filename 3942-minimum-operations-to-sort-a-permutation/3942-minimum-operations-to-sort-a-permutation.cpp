class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[next] != (nums[i] + 1) % n) {
                increasing = false;
            }

            if (nums[next] != (nums[i] - 1 + n) % n) {
                decreasing = false;
            }
        }

        if (increasing) {
            return min(z, n - z + 2);
        }

        if (decreasing) {
            int posMax = (z + 1) % n;
            return min(n - z, posMax + 1);
        }

        return -1;
    }
};