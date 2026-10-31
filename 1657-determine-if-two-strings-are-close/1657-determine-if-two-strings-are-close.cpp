class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;

        unordered_map<char, int> freq1, freq2;
        for (char c : word1)
            freq1[c]++;
        for (char c : word2)
            freq2[c]++;

        if (freq1.size() != freq2.size())
            return false;
            
        for (auto& x : freq1) {
            if (freq2.find(x.first) == freq2.end())
                return false;
        }
        vector<int> counts1, counts2;
        for (const auto& pair : freq1)
            counts1.push_back(pair.second);
        for (const auto& pair : freq2)
            counts2.push_back(pair.second);

        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};