class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        // Create a result vector to hold the final order of cards
        vector<int> result(deck.size());
        for (int card : deck) { // Iterate through the sorted deck
            result[q.front()] = card;
            q.pop();
            if (!q.empty()) { // If there are still indices left in the queue,
                              // move the next index to the back of the queue
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};