class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap; // To store the count of each number
        for (int num : arr) {
            countMap[num]++;
        }

        unordered_map<int, int>
            occurrenceMap; // To store the occurrences of counts
        for (const auto& pair : countMap) {
            occurrenceMap[pair.second]++;
            if (occurrenceMap[pair.second] > 1) {
                return false; // If any count occurs more than once, return
                              // false
            }
        }

        return true; // All counts are unique
    }
};