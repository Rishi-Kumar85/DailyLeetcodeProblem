class Solution {
public:

    string buildPalindrome(string left, char middle) {

        string right = left;

        reverse(right.begin(), right.end());

        if(middle==0) return left+right;

        return left + string(1, middle) + right;
    }

    bool possible(string prefix,
                  int cnt[],
                  char middle,
                  string target) {

        string left = prefix;

        // Put all remaining characters in DESCENDING order.
        // This gives the largest possible left half.
        for (int c = 25; c >= 0; c--) {

            while (cnt[c] > 0) {
                left += char('a' + c);
                cnt[c]--;
            }
        }

        string candidate = buildPalindrome(left, middle);

        return candidate > target;
    }


    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        int cnt[26] = {};

        // Count characters
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int c = 0; c < 26; c++) {

            if (cnt[c] % 2 == 1) {
                odd++;
                middle = char('a' + c);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Build counts for LEFT HALF
        int halfCnt[26];

        for (int c = 0; c < 26; c++) {
            halfCnt[c] = cnt[c] / 2;
        }

        int halfLen = n / 2;

        string prefix = "";

        // Build left half
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (halfCnt[c] == 0) {
                    continue;
                }

                // Temporarily choose this character
                prefix += char('a' + c);
                halfCnt[c]--;

                // Make a COPY for checking
                int temp[26];

                for (int j = 0; j < 26; j++) {
                    temp[j] = halfCnt[j];
                }

                if (possible(prefix, temp, middle, target)) {

                    // This character works
                    found = true;
                    break;
                }

                // This character doesn't work
                // Undo it
                halfCnt[c]++;
                prefix.pop_back();
            }

            if (!found) {
                return "";
            }
        }

        // Construct final answer
        string answer = buildPalindrome(prefix, middle);

        if (answer > target) {
            return answer;
        }

        return "";
    }
};