class Solution {
public:
    double pow(double x,long long n){
       if(n==0) return 1;
       double halfpow=pow(x,n/2);
       if(n%2==0) return halfpow*halfpow;
       else return halfpow*halfpow*x;
    }
    double myPow(double x, int n) {
        long long N = n;
    if(N<0) {
        double p= pow(x,-N);
        return 1.0/p;
    }
    return pow(x,n);
    }
};