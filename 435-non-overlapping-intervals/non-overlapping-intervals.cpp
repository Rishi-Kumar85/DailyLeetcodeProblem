class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

       int prev = 0;
        int count = 1;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return intervals.size() - count;

    }
};