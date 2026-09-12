class Solution {
public:

    struct Node {
        int l;
        int r;
        int weight;
        int index;
    };

    struct State {
        long long score;
        vector<int> indices;
    };

    vector<Node> a;
    vector<vector<State>> dp;
    vector<vector<bool>> seen;

    bool better(const State& x, const State& y) {

        if (x.score != y.score)
            return x.score > y.score;

        return x.indices < y.indices;
    }

    int findNext(int i) {

        int target = a[i].r + 1;

        int lo = i + 1;
        int hi = a.size();

        while (lo < hi) {

            int mid = lo + (hi - lo) / 2;

            if (a[mid].l >= target)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    State solve(int i, int k) {

        if (i == a.size() || k == 0)
            return {0, {}};

        if (seen[i][k])
            return dp[i][k];

        seen[i][k] = true;

        // Option 1: skip current interval
        State skip = solve(i + 1, k);

        // Option 2: take current interval
        int next = findNext(i);

        State take = solve(next, k - 1);

        take.score += a[i].weight;
        take.indices.push_back(a[i].index);

        sort(take.indices.begin(), take.indices.end());

        if (better(take, skip))
            dp[i][k] = take;
        else
            dp[i][k] = skip;

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {

            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(),
             [](const Node& x, const Node& y) {
                 if (x.l != y.l)
                     return x.l < y.l;

                 return x.r < y.r;
             });

        dp.resize(n, vector<State>(5));
        seen.resize(n, vector<bool>(5, false));

        return solve(0, 4).indices;
    }
};