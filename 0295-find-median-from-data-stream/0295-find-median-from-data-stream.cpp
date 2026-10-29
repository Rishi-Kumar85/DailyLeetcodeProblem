class MedianFinder {
public:
    priority_queue<int> maxHeap; // to store the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>>
        minHeap; // to store the larger half of the numbers

    MedianFinder() {}
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() >
            minHeap.size() + 1) { // maxHeap has more than one extra element
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() >
                   maxHeap.size()) { // minHeap has more elements than maxHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */