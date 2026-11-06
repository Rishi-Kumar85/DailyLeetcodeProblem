class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        // Store {query time, original index}
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        // Sort queries by time
        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto [time, index] : q) {

            int L = time - x;
            int R = time;

            // Add logs entering the window
            while (right < logs.size() &&
                   logs[right][1] <= R) {

                int id = logs[right][0];

                if (freq[id] == 0) {
                    active++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs leaving the window
            while (left < logs.size() &&
                   logs[left][1] < L) {

                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    active--;
                }

                left++;
            }

            ans[index] = n - active;
        }

        return ans;
    }
};