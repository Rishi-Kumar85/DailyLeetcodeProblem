class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = 0;

        // Prefix sum 0 has occurred once
        mp[0] = 1;

        for (int num : nums) {
            sum += num;

            int required = sum - k;

            if (mp.find(required) != mp.end()) {
                ans += mp[required];
            }

            mp[sum]++;
        }

        return ans;
    }
};