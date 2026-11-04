
class Solution {
private:
    multiset<long long> left, right;

    long long sumLeft = 0;
    long long sumRight = 0;

    // Maintain the correct number of elements in left
    void balance(int target) {

        while (left.size() > target) {
            auto it = prev(left.end());

            long long val = *it;
            left.erase(it);

            sumLeft -= val;
            right.insert(val);
            sumRight += val;
        }

        while (left.size() < target && !right.empty()) {
            auto it = right.begin();

            long long val = *it;
            right.erase(it);

            sumRight -= val;
            left.insert(val);
            sumLeft += val;
        }
    }

    // Insert a number into the window
    void addNum(long long val, int target) {

        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        }
        else {
            right.insert(val);
            sumRight += val;
        }

        balance(target);
    }

    // Remove a number from the window
    void removeNum(long long val, int target) {

        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        }
        else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance(target);
    }

    // Calculate cost of making current window equal
    long long getCost() {

        long long median = *left.rbegin();

        long long costLeft =
            median * left.size() - sumLeft;

        long long costRight =
            sumRight - median * right.size();

        return costLeft + costRight;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Required input copy
        vector<int> maritovexi = nums;

        int target = (x + 1) / 2;

        vector<long long> cost(n - x + 1);

        // Build the first window
        for (int i = 0; i < x; i++) {
            addNum(maritovexi[i], target);
        }

        cost[0] = getCost();

        // Slide the window
        for (int i = x; i < n; i++) {

            removeNum(maritovexi[i - x], target);

            addNum(maritovexi[i], target);

            cost[i - x + 1] = getCost();
        }

        // DP initialization
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        // Selecting zero windows costs zero
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        // DP transitions
        for (int t = 1; t <= k; t++) {

            for (int i = 1; i <= n; i++) {

                // Option 1: Skip current element
                dp[t][i] = dp[t][i - 1];

                // Option 2: Select a window ending at i-1
                if (i >= x &&
                    dp[t - 1][i - x] != INF) {

                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
