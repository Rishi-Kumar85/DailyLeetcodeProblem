class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2,
                             int d) {

      int ans = 0;
      for(int a : arr1){
           bool valid = true;
        for(int b : arr2){
            if(abs(a-b) <= d) {
                valid = false;
                break;
            }
        }
        if(valid) ans++;
      }
      return ans;

    }
};