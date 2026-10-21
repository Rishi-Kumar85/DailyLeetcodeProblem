class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> digitCount;
        for (int digit : digits) {
            digitCount[digit]++;
        }

        vector<int> result;
        for (int i = 100; i <= 999; i += 2) { // Only even numbers
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int units = i % 10;

            if (digitCount[hundreds] > 0 && digitCount[tens] > 0 &&
                digitCount[units] > 0) {
                // Check if we can form the number with available digits
                unordered_map<int, int> tempCount = digitCount;
                tempCount[hundreds]--;
                tempCount[tens]--;
                tempCount[units]--;

                if (tempCount[hundreds] >= 0 && tempCount[tens] >= 0 &&
                    tempCount[units] >= 0) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};