class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
         unordered_set<string> s;
    int count = 0;
    for(const string& word : words) {
        string reversed = word;
        reverse(reversed.begin(), reversed.end());
        if(s.find(reversed) != s.end()) {
            count++;
        }
        s.insert(word);
    }
    return count; 
    }
};