class Solution {
public:
    int minCost(int n, vector<int>& cost, vector<int>& memo) {
        if (n <= 1)
            return cost[n];
        if (memo[n] != -1)
            return memo[n];
        memo[n] = cost[n] +
                  min(minCost(n - 1, cost, memo), minCost(n - 2, cost, memo));
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        return min((minCost(n-1,cost,memo)),(minCost(n-2,cost,memo)));
    }
};