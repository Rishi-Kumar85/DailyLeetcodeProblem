class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        
        // Store the last occurrence of every character
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If already present in stack, skip it
            if (visited[ch - 'a']) {
                continue;
            }

            // Remove bigger characters if they occur again later
            while (!st.empty() &&
                   st.top() > ch &&
                   last[st.top() - 'a'] > i) {
                
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Convert stack to string
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};