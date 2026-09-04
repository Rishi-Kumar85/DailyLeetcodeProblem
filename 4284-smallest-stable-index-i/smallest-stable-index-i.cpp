class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
           int maximum=*max_element(nums.begin(),nums.begin()+i+1);
           int min = *min_element(nums.begin()+i,nums.end());
           if(maximum-min<=k) return i;
        }
        return -1;
    }
};