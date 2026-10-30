
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Distance for each (node, count) state
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );

        // Step 3: Min priority queue
        // {distance, node, consecutive count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Starting node's label counts as 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 4: Dijkstra
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt])
                continue;

            // Destination reached
            if (u == n - 1)
                return (int)d;

            // Explore neighbours
            for (auto [v, w] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                // Invalid path
                if (newCnt > k)
                    continue;

                long long newDist = d + w;

                // Relaxation
                if (newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCnt
                    });
                }
            }
        }

        // No valid path exists
        return -1;
    }
};
