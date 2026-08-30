class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {

            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Put smaller index in left
        // and larger index in right
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Three possibilities
        int frontOnly = right + 1;

        int backOnly = n - left;

        int bothSides = left + 1 + n - right;

        return min({frontOnly, backOnly, bothSides});
    }
};