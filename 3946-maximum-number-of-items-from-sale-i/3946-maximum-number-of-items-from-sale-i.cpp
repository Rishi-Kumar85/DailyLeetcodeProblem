
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // dp[b] = maximum reward using at most b budget
        vector<int> dp(budget + 1, 0);

        int minPrice = INT_MAX;

        // Process every item type
        for (int i = 0; i < n; i++) {

            int factor = items[i][0];
            int price = items[i][1];

            minPrice = min(minPrice, price);

            // Calculate first-purchase reward
            int cnt = 0;

            for (int j = 0; j < n; j++) {

                if (items[j][0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack: traverse backwards
            for (int b = budget; b >= price; b--) {

                dp[b] = max(
                    dp[b],
                    dp[b - price] + cnt
                );
            }
        }

        // Spend leftover budget on cheapest items
        int ans = 0;

        for (int b = 0; b <= budget; b++) {

            int extra = (budget - b) / minPrice;

            ans = max(ans, dp[b] + extra);
        }

        return ans;
    }
};
