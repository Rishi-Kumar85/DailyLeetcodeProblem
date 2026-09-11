class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {0};

        // Count how many times each digit appears
        for (int d : digits) {
            freq[d]++;
        }

        vector<int> ans;

        // Choose hundreds digit
        for (int i = 1; i <= 9; i++) {

            if (freq[i] == 0)
                continue;

            freq[i]--;

            // Choose tens digit
            for (int j = 0; j <= 9; j++) {

                if (freq[j] == 0)
                    continue;

                freq[j]--;

                // Choose units digit
                for (int k = 0; k <= 8; k += 2) {

                    if (freq[k] == 0)
                        continue;

                    int number = i * 100 + j * 10 + k;

                    ans.push_back(number);
                }

                // Restore tens digit
                freq[j]++;
            }

            // Restore hundreds digit
            freq[i]++;
        }

        return ans.size();
    }
};