class Solution {
public:
       vector<int> nextGreaterElementArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ng=nextGreaterElementArray(nums2);
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=ng[j];
                    break;
                }
            }
        }
        return ans;
    }
};