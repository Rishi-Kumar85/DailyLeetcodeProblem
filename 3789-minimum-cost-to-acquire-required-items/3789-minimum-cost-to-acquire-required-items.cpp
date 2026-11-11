class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        int needMin = min(need1, need2);
        int mincost = min(costBoth, cost1 + cost2);
        long long  total = 1LL * needMin * mincost;
        int remtype1 = need1 - needMin;
        if (remtype1 > 0)
            total += 1LL * remtype1 * min(costBoth, cost1);
        int remtype2 = need2 - needMin;
        if (remtype2 > 0)
            total += 1LL * remtype2 * min(costBoth, cost2);
        return total;
    }
};