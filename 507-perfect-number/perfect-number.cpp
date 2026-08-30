class Solution {
public:
    bool checkPerfectNumber(int num) {
         if (num <= 1) return false; // 0 and 1 are not perfect numbers
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add the divisor to the sum
        }
    }
    return sum == num; // Check if the sum of divisors equals the number
    }
};