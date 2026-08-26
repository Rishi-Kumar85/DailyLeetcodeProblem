class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);
        half = (half * half) % MOD;

        if (n % 2 == 1)
            half = (half * x) % MOD;

        return half;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};