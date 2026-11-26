class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int a = 10;
        bool alice = true;
        while(n>0) {
            n=n-a;
            a--;
            if(n>=a) alice=!alice; 

        }
        return alice;
        
    }
};