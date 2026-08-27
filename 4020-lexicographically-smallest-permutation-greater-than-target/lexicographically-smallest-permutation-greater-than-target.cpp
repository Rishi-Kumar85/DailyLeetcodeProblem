class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
          int n = s.size();

        int cnt[26] = {};

        // Count characters
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string prefix = "";

        // Try to match target
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Cannot match target[i]
            if (cnt[x] == 0) {

                // Try smallest character greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (cnt[c] > 0) {

                        string ans = prefix;

                        ans += char('a' + c);
                        cnt[c]--;

                        // Smallest possible suffix
                        for (int j = 0; j < 26; j++) {
                            while (cnt[j] > 0) {
                                ans += char('a' + j);
                                cnt[j]--;
                            }
                        }

                        return ans;
                    }
                }

                break;
            }

            prefix += target[i];
            cnt[x]--;
        }

        // We matched target completely.
        // Now backtrack.
        for (int i = prefix.size()-1; i >= 0; i--) {

            // Put prefix[i] back
            cnt[prefix[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string ans = prefix.substr(0, i);

                    ans += char('a' + c);
                    cnt[c]--;

                    // Fill remaining characters smallest first
                    for (int j = 0; j < 26; j++) {

                        while (cnt[j] > 0) {
                            ans += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};