class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                // If the next character is not ')',
                // insert one ')' to complete the pair.
                if (i + 1 >= n || s[i + 1] != ')') {
                    ans++;
                } else {
                    // Consume the second ')' of the pair.
                    i++;
                }

                // Match this pair with an opening '('.
                if (!st.empty()) {
                    st.pop();
                } else {
                    // Insert a missing opening '('.
                    ans++;
                }
            }
        }

        // Each unmatched '(' needs two closing parentheses.
        ans += 2 * st.size();

        return ans;
    }
};