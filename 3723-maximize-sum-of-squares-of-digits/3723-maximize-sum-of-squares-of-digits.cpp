class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }

       

        string ans = "";

        // Use as many 9s as possible.
        int count9 = sum / 9;

        for (int i = 0; i < count9; i++) {
            ans += '9';
        }

        sum %= 9;

        // Add the leftover digit if necessary.
        if (sum > 0) {
            ans += char('0' + sum);
        }

        // Fill the remaining places with zeros.
        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};