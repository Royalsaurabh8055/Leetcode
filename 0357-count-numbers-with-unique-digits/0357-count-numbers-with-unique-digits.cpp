class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int total = 10; // covers n=1 case (0-9)
        int uniqueDigits = 9; // choices for the first digit (1-9)
        int availableDigits = 9; // choices for remaining digits (0-9 excluding first)
        
        for (int i = 2; i <= n && availableDigits > 0; i++) {
            uniqueDigits *= availableDigits;
            total += uniqueDigits;
            availableDigits--;
        }
        
        return total;
    }
};