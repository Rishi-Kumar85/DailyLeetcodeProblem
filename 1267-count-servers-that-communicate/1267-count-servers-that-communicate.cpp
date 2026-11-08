class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // First pass: count servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int ans = 0;

        // Second pass: count communicating servers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 &&
                    (rowCount[i] > 1 || colCount[j] > 1)) {

                    ans++;
                }
            }
        }

        return ans;
    }
};