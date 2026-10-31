class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;
        for (int num : arr) {
            int remainder =
                ((num % k) + k) % k; // Handle negative numbers Example: -1 % 5
                                     // = -1, but we want it to be 4
            remainderCount[remainder]++;
        }

        for (const auto& pair : remainderCount) {
            int rem = pair.first;
            int count = pair.second;

            if (rem == 0) {
                if (count % 2 != 0)
                    return false; // Remainder 0 must be even
            } else {
                int complement = k - rem;
                if (remainderCount[complement] != count)
                    return false; // Check complement
            }
        }
        return true;
    }
};