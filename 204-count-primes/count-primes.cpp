class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        // Remove even numbers
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        // Sieve only using odd numbers
        for (int i = 3; (long long)i * i < n; i += 2) {
            if (isPrime[i]) {
                for (long long j = (long long)i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 1;  // number 2 is prime

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                ans++;
        }

        return ans;
    }
};