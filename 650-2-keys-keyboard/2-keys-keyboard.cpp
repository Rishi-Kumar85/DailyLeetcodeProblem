class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int gd(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return n/i;
        }
        return 1;
    }
    int minSteps(int n) {
        int count=0;
        while(n>1){
            if(isPrime(n)){
                count+=n;
                break;
            }
            int hf=gd(n);
            count+=n/hf;
            n=hf;
        }
        return count;
    }
};