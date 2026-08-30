class Solution {
public:
bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // n is divisible by i, hence not prime
    }
    return true; // n is prime
}
    int diagonalPrime(vector<vector<int>>& nums) {
       int mx=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(isPrime(nums[i][i])){
            mx=max(mx,nums[i][i]);
        }
        if(isPrime(nums[i][n-i-1])){
            mx=max(mx,nums[i][n-i-1]);
        }

       }
        
        return mx;
    }
};