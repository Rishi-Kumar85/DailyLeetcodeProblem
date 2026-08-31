class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
                priority_queue<int> pq;

        // Put all stones into max-heap
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {

            // Largest stone
            int y = pq.top();
            pq.pop();

            // Second largest stone
            int x = pq.top();
            pq.pop();

            // If they are different,
            // put the remaining weight back
            if (x != y) {
                pq.push(y - x);
            }
        }

        // Either one stone remains or none
        if (pq.empty()) {
            return 0;
        }

        return pq.top();

    }
};