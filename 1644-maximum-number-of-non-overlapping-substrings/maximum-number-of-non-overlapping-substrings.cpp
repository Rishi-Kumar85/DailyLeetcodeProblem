class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1) {
                continue;
            }

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {

                int current = s[i] - 'a';

                // This character appeared before left
                if (first[current] < left) {
                    valid = false;
                    break;
                }

                // We need to include all occurrences
                right = max(right, last[current]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Sort by ending position
        sort(
            intervals.begin(),
            intervals.end(),
            [](pair<int, int>& a, pair<int, int>& b) {
                return a.second < b.second;
            }
        );

        vector<string> ans;

        int previousEnd = -1;

        for (auto interval : intervals) {

            int left = interval.first;
            int right = interval.second;

            if (left > previousEnd) {

                ans.push_back(
                    s.substr(left, right - left + 1)
                );

                previousEnd = right;
            }
        }

        return ans;
    }
};