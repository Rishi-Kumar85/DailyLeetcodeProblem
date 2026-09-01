class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int startR = -1;
        int startC = -1;

        // Store all litter positions
        vector<pair<int, int>> litter;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter
        if (k == 0) {
            return 0;
        }

        // 2^k possible masks
        int totalMasks = 1 << k;

        /*
            dist[r][c][e][mask]

            r    = current row
            c    = current column
            e    = remaining energy
            mask = litter already collected
        */

        vector<vector<vector<vector<int>>>> dist(
            n,
            vector<vector<vector<int>>>(
                m,
                vector<vector<int>>(
                    energy + 1,
                    vector<int>(totalMasks, -1)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        // Starting state
        q.push({startR, startC, energy, 0});

        dist[startR][startC][energy][0] = 0;

        // Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask] = q.front();
            q.pop();

            int moves = dist[r][c][e][mask];

            // All litter collected
            if (mask == totalMasks - 1) {
                return moves;
            }

            // Try 4 directions
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside classroom
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m) {
                    continue;
                }

                // Obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                // Moving costs 1 energy
                int ne = e - 1;

                // Cannot move without energy
                if (ne < 0) {
                    continue;
                }

                int nmask = mask;

                // Check if we reached a litter
                for (int i = 0; i < k; i++) {

                    if (litter[i].first == nr &&
                        litter[i].second == nc) {

                        // Mark litter i as collected
                        nmask |= (1 << i);

                        break;
                    }
                }

                // R restores energy to maximum
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                // If this state has not been visited
                if (dist[nr][nc][ne][nmask] == -1) {

                    dist[nr][nc][ne][nmask] =
                        moves + 1;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask
                    });
                }
            }
        }

        return -1;
    }
};