class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Base cases: The cost to reach the first two steps is just their
        // respective costs
        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        // The minimum cost to reach the top is the smaller of the costs to
        // reach the last two steps
        return min(cost[n - 1], cost[n - 2]);
    }
};