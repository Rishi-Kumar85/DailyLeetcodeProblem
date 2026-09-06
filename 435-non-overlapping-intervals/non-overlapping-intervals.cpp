class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;

        int previousEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            // Overlap
            if (intervals[i][0] < previousEnd) {

                removed++;

                // Keep the interval that ends earlier
                previousEnd =
                    min(previousEnd, intervals[i][1]);
            }
            else {

                // No overlap
                previousEnd = intervals[i][1];
            }
        }

        return removed;

    }
};