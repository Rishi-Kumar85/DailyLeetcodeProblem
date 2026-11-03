class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(int num : nums){
            ans += (maximum-num);
        }
        return ans;
    }
};