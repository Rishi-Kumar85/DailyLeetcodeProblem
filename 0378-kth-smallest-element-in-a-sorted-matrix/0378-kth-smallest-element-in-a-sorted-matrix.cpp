class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
          int n = matrix.size();
    priority_queue<int> maxHeap; // max heap to store the k smallest elements
    int m = matrix[0].size();
    // find in which row the kth smallest element is present as the matrix is sorted row-wise and column-wise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxHeap.push(matrix[i][j]);
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove the largest element if size exceeds k
            }
        }
    }
    return maxHeap.top(); // return the kth smallest element
    }
};