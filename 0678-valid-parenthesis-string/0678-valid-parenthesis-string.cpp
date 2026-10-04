class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else {
                // '*' can be ')', empty, or '('
                low--;
                high++;
            }

            // Minimum balance cannot be negative
            low = max(0, low);

            // Even the maximum balance is negative
            // means we can never make the string valid
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};