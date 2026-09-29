class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> s;

    // Calculate left limits - the index of the previous smaller element for each bar
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack to reuse it for right limits
    while (!s.empty()) {
        s.pop();
    }
    // Calculate right limits - the index of the next smaller element for each bar
    for(int i=0; i<n; i++){
        while(!s.empty() && heights[s.top()] > heights[i]){
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);

    }
    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
    }
};