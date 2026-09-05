class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minimum(n);
        minimum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            minimum[i]=min(nums[i],minimum[i+1]);
        }
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
           maximum=max(nums[i],maximum);
           int score=maximum-minimum[i];
           if(score<=k){
            return i;
           }
        }
        return -1;
    }
};