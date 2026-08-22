class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int  n = nums.size();
       int sum=0;
       int minLength=INT_MAX;
       int length=0;
       int i=0;
       int j=0;
       while(j<n){
        sum+=nums[j];
        while(sum>=target){
            length=j-i+1;
            minLength=min(minLength,length);
            sum-=nums[i];
            i++;
        }
        j++;
       }
      if(minLength==INT_MAX) return 0;
      return minLength;
    }
};