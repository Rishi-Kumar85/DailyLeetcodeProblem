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

        unordered_map<int, int> countFreq1, countFreq2;
        for (auto& x : freq1)
            countFreq1[x.second]++;
        for (auto& x : freq2)
            countFreq2[x.second]++;

        return countFreq1 == countFreq2;
    }
};