
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Step 1: Build the Suffix Array
    vector<int> buildSA(vector<int>& nums) {

        int n = nums.size();

        vector<int> sa(n);
        vector<int> rank = nums;
        vector<int> nextRank(n);

        iota(sa.begin(), sa.end(), 0);

        // Double the prefix length in each iteration
        for (int len = 1; len < n; len *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {

                if (rank[a] != rank[b]) {
                    return rank[a] < rank[b];
                }

                int secondA = (a + len < n)
                              ? rank[a + len] : -1;

                int secondB = (b + len < n)
                              ? rank[b + len] : -1;

                return secondA < secondB;
            });

            // Assign new ranks
            nextRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {

                int prev = sa[i - 1];
                int curr = sa[i];

                int prevSecond = (prev + len < n)
                                 ? rank[prev + len] : -1;

                int currSecond = (curr + len < n)
                                 ? rank[curr + len] : -1;

                bool different =
                    rank[prev] != rank[curr] ||
                    prevSecond != currSecond;

                nextRank[curr] =
                    nextRank[prev] + different;
            }

            rank.swap(nextRank);

            // All suffixes have different ranks
            if (rank[sa[n - 1]] == n - 1) {
                break;
            }
        }

        return sa;
    }

    // Step 2: Build LCP array using Kasai's algorithm
    vector<int> buildLCP(vector<int>& nums,
                         vector<int>& sa,
                         vector<int>& pos) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        vector<int> lcp(n, 0);

        int h = 0;

        for (int i = 0; i < n; i++) {

            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n &&
                   j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0) {
                h--;
            }
        }

        return lcp;
    }

    // Step 3: Find the smallest unique subarray
    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> sa = buildSA(nums);

        vector<int> pos(n, 0);

        vector<int> lcp = buildLCP(nums, sa, pos);

        int ans = n;

        for (int i = 0; i < n; i++) {

            int r = pos[i];

            int maxCommon = 0;

            // LCP with previous suffix
            if (r > 0) {
                maxCommon = max(maxCommon, lcp[r]);
            }

            // LCP with next suffix
            if (r + 1 < n) {
                maxCommon = max(maxCommon, lcp[r + 1]);
            }

            int uniqueLength = maxCommon + 1;

            // Check whether this length fits
            if (uniqueLength <= n - i) {
                ans = min(ans, uniqueLength);
            }
        }

        return ans;
    }
};
