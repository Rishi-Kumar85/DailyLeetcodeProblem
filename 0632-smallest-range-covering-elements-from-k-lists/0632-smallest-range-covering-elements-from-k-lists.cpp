class Solution {
public:
    typedef pair<int, pair<int, int>>
        Element; // {value, {array_index, element_index}}

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        int currentMax = INT_MIN;

        // Initialize the heap with the first element of each array
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            Element top = minHeap.top();
            int currentMin = top.first;
            pair<int, int> indices = top.second;
            minHeap.pop();

            // Update the range if the current range is smaller
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // Move to the next element in the same array
            int arrayIndex = indices.first;
            int elementIndex = indices.second + 1;

            if (elementIndex < nums[arrayIndex].size()) {
                int nextValue = nums[arrayIndex][elementIndex];
                minHeap.push({nextValue, {arrayIndex, elementIndex}});
                currentMax = max(currentMax, nextValue);
            } else {
                break; // One of the arrays is exhausted
            }
        }

        return {rangeStart, rangeEnd};
    }
    // TC: O(n log k) where n is the total number of elements across all arrays
    // and k is the number of arrays, SC: O(k) for the heap where k is the
    // number of arrays
};