class Solution {
public:
    int smallestNumber(int n) {
         int count = 0;
    int temp = n;
    while (temp) {
        count++;
        temp >>= 1;
    }
    int mask = (1 << count) - 1;
    return mask;
    }

};