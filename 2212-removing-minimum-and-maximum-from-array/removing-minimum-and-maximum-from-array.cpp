class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());
        int minVal= *min_element(nums.begin(),nums.end());
        int n = nums.size();
        int minIdx=-1;
        for(int i=0;i<n;i++){
            if(minVal==nums[i]) {
                minIdx=i;
                break;
            }
        }
        int maxIdx=-1;
          for(int i=0;i<n;i++){
            if(maxVal==nums[i]) {
                maxIdx=i;
                break;
            }
        }
        int front=max(minIdx,maxIdx)+1;
        int back=n-min(minIdx,maxIdx);
        int both=n-max(minIdx,maxIdx)+min(minIdx,maxIdx)+1;
        return min(front,min(back,both));


    }
};