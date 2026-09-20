class Solution {
public:
    int reverseDegree(string s) {
        vector<int> position(26,0);
        for(int i=0;i<26;i++){
            position[i]=26-i;
        }
         int ans=0;
         int i=1;
        for(char c : s){
            int idx = c - 'a';
              ans+= position[idx] * i;
              i++;
        }

        return ans;
    }
};