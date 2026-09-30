class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       int n = heights.size();
    vector<int> visibleCount(n, 0);
    stack<int> s; // Stack to store indices of people

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while the current height is greater than or equal to the height at the index stored in the stack
        while (!s.empty() && heights[s.top()] <= heights[i]) {
            visibleCount[s.top()]++; // The person at s.top() can see the current person
            s.pop();
        }
        if (!s.empty()) {
            visibleCount[s.top()]++; // The person at s.top() can see the current person
        }
        s.push(i); // Push the current index onto the stack
    }
    return visibleCount;
    }
};