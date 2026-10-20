class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Prefix maximum: maximum among elements before index i.
        vector<int> prefMax(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Suffix minimum: minimum from index i to the end.
        const int INF = 1'000'000'000;
        vector<int> suffMin(n + 1, INF);

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Prefix count of adjacent descents.
        vector<int> prefDrop(n, 0);

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        // Check whether block length k is sortable.
        auto check = [&](int k) -> bool {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Count descents inside this block.
                int drops = prefDrop[end] - prefDrop[start];

                // Include the circular connection: last -> first.
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // A block needs at most one circular descent.
                if (drops > 1) {
                    return false;
                }

                // Values must also join correctly across boundaries.
                if (prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        // Enumerate divisors in O(sqrt(n)).
        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                int other = n / d;

                if (check(d)) {
                    ans += d;
                }

                // Avoid checking a square-root divisor twice.
                if (d != other && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};