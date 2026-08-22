class Solution {
public:
    int longestSubarray(vector<int>& arr) {
         int n = arr.size();
    int i=0,j=0;
    int k=1;
    int maxlen = INT_MIN, len = INT_MIN;
    while(j<n){
        if(arr[j]==0) k--;
        if(k<0){
            len=j-i;
            maxlen=max(maxlen,len);
            while(arr[i]==1) i++;
            i++;
            k++;
        }
        j++;
    }
    len=j-i;
    maxlen=max(maxlen,len);
    return maxlen-1;
    }
};