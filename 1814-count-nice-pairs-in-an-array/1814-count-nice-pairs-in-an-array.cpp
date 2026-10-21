class Solution {
public:
    int countNicePairs(vector<int>& nums) {
          long long MOD = 1e9 + 7;
  unordered_map<int, int> countMap;
  int nicePairs = 0;
  for(int num : nums) {
    int revNum = 0, originalNum = num;
    while(num > 0) {
      revNum = revNum * 10 + num % 10;
      num /= 10;
    }
    int diff = originalNum - revNum;
    nicePairs = (nicePairs + countMap[diff]) % MOD;
    countMap[diff]++;
  }
  return nicePairs;
    }
};