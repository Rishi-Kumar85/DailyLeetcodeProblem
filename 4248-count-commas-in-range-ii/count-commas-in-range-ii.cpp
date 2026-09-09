class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long x = 1000; x <= n; ) {

            ans += n - x + 1;

            // Prevent unnecessary overflow
            if (x > n / 1000)
                break;

            x *= 1000;
        }

        return ans;


    }
};