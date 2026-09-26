class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Step 1: Store key -> value
        unordered_map<string, string> mp;

        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans;

        // Step 2: Traverse the string
        int i = 0;

        while (i < s.length()) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }

            // Bracket pair
            else {

                int j = i + 1;

                // Find closing bracket ')'
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check whether key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }

                // Skip entire bracket pair
                i = j + 1;
            }
        }

        return ans;
    }
};