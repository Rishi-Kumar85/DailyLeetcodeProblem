class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initially, every cell is an obstacle.
        vector<string> grid(m, string(n, '#'));

        // Open every cell in the first row.
        grid[0] = string(n, '.');

        // Open every cell in the last column.
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};