class Solution {
public:

    string s;
    int pos = 0;

    // Concatenate two sets
    set<string> multiply(const set<string>& A,
                         const set<string>& B) {

        set<string> result;

        for (const string& a : A) {
            for (const string& b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    // Expression:
    // term , term , term ...
    set<string> parseExpression() {

        set<string> result = parseTerm();

        while (pos < s.size() && s[pos] == ',') {

            pos++;  // skip ','

            set<string> next = parseTerm();

            // Union
            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // Term:
    // factor factor factor ...
    set<string> parseTerm() {

        set<string> result;
        bool first = true;

        while (pos < s.size() &&
               s[pos] != ',' &&
               s[pos] != '}') {

            set<string> current;

            // Factor is a letter
            if (isalpha(s[pos])) {

                string word(1, s[pos]);
                pos++;

                current.insert(word);
            }

            // Factor is {...}
            else if (s[pos] == '{') {

                pos++;  // skip '{'

                current = parseExpression();

                pos++;  // skip '}'
            }

            // Concatenation
            if (first) {
                result = current;
                first = false;
            }
            else {
                result = multiply(result, current);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};