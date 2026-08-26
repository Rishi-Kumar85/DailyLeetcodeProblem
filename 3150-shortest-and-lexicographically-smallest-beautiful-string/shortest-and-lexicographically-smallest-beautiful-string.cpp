class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
          int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // Too many ones -> shrink from left
            while (ones > k) {

                if (s[left] == '1') {
                    ones--;
                }

                left++;
            }

            // Exactly k ones -> remove unnecessary zeros
            while (ones == k && s[left] == '0') {
                left++;
            }

            // We found a beautiful substring
            if (ones == k) {

                string curr = s.substr(left, right - left + 1);

                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {

                    ans = curr;
                }
            }
        }

        return ans;
    }
};