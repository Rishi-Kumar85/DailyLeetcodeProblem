class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = 1;
        int mxlength = 1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]) length++;
            else length = 1;

            mxlength = max(length,mxlength);
        }
        length = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]) length++;
            else length = 1;

            mxlength = max(length,mxlength);
        }

        return mxlength;
    }
};