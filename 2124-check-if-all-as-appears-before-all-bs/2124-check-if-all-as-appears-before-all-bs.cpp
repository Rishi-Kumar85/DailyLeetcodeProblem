class Solution {
public:
    bool checkString(string s) {
        if(s.length()==1) return true;
        int lastA = -1;
        int firstB = -1;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='a') lastA = i;
            
        }
          for(int i = 0;i<s.length();i++){
            if(s[i]=='b'){ 
                firstB = i;
                break;
            }
            
        }
        if(firstB==-1 || lastA ==-1) return true;
        if(firstB<lastA) return false;
        return true;
    }
};