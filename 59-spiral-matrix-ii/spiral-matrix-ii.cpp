class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     vector<vector<int>>v(n,vector<int>(n,0));
      int minr =0, minc=0, maxr=n-1, maxc=n-1;
      int cnt=1;
    while(minr<=maxr && minc<=maxc){
        // print top row
        for(int i=minc;i<=maxc;i++){
           v[minr][i]=cnt;
           cnt++;
        }
        minr++;
        if(minr>maxr || minc>maxc) break;

        // print right column
        for(int i=minr;i<=maxr;i++){
             v[i][maxc]=cnt;
             cnt++;
        }
        maxc--;
        if(minr>maxr || minc>maxc) break;

        // print bottom row
        if(minr<=maxr){
            for(int i=maxc;i>=minc;i--){
                 v[maxr][i]=cnt++;
            }
            maxr--;
        }
        if(minr>maxr || minc>maxc) break;
        // print left column
        if(minc<=maxc){
            for(int i=maxr;i>=minr;i--){
                v[i][minc]=cnt;
                cnt++;
            }
            minc++;
            if(minr>maxr || minc>maxc) break;
        }
    }  
  return v;
    }
};