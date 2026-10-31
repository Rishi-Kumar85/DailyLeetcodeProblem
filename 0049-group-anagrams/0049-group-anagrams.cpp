class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for (const string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            anagramGroups[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        return result;
    }
};