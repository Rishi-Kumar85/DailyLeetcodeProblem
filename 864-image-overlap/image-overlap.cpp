class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>ones1;
        vector<pair<int,int>>ones2;

        for(int r=0;r<img1.size();r++){
            for(int c=0;c<img1[0].size();c++){
                if(img1[r][c]==1) ones1.push_back({r,c});
                if(img2[r][c]==1) ones2.push_back({r,c});

            }
        }

        map<pair<int,int>,int>mp;
          int ans=0;
        for(auto p1 : ones1){
              for(auto p2: ones2){
                int dr = p2.first-p1.first;
                int dc = p2.second-p1.second;
                mp[{dr,dc}]++;

                ans = max(ans,mp[{dr,dc}]);
              }
        }
             
             return ans;


    }
};