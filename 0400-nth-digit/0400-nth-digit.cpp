class Solution {
public:
    int findNthDigit(int n) {

        long long digits = 1;   // number of digits
        long long count = 9;    // how many numbers
        long long start = 1;    // first number in this group

        // Find which digit-length group contains n
        while (n > digits * count) {

            n -= digits * count;

            digits++;
            count *= 10;
            start *= 10;
        }

        // Find the actual number containing nth digit
        long long number = start + (n - 1) / digits;

        // Find which digit inside that number
        int index = (n - 1) % digits;

        string s = to_string(number);

        return s[index] - '0';
    }
};