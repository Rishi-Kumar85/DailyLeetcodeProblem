class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        // Store positions of 1s in img1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (img1[r][c] == 1) {
                    ones1.push_back({r, c});
                }

                if (img2[r][c] == 1) {
                    ones2.push_back({r, c});
                }
            }
        }

        map<pair<int, int>, int> count;

        int ans = 0;

        // Compare every 1 in img1 with every 1 in img2
        for (auto p1 : ones1) {

            for (auto p2 : ones2) {

                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                count[{dr, dc}]++;

                ans = max(ans, count[{dr, dc}]);
            }
        }

        return ans;
    }
};