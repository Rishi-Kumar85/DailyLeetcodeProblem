class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        // Count requests handled by each server
        vector<int> cnt(k, 0);

        // Store {finishTime, serverId}
        // Min-heap: earliest finishing server comes first
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // Initially, all servers are available
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Process every request
        for (int i = 0; i < arrival.size(); i++) {

            long long currentTime = arrival[i];

            // Release all servers that have finished
            while (!busy.empty() &&
                   busy.top().first <= currentTime) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // No server is available
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Remove server from available set
            available.erase(it);

            // Calculate finishing time
            long long finishTime = currentTime + load[i];

            // Mark server as busy
            busy.push({finishTime, server});

            // Increase request count
            cnt[server]++;
        }

        // Find maximum number of handled requests
        int maxCount = *max_element(cnt.begin(), cnt.end());

        // Collect all busiest servers
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxCount) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};