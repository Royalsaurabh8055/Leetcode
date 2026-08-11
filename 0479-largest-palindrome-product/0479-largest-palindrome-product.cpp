class Solution {
public:

    int largestPalindrome(int n) {

        // Special case
        if (n == 1)
            return 9;

        int mx = pow(10, n) - 1;

        // Generate palindrome using first half
        for (int left = mx; left >= mx / 10; left--) {

            long long palindrome = left;
            int x = left;

            // Reverse left and append it
            while (x > 0) {
                palindrome = palindrome * 10 + (x % 10);
                x /= 10;
            }

            // Check if palindrome can be divided
            // into two n-digit numbers
            for (long long i = mx; i * i >= palindrome; i--) {

                if (palindrome % i == 0) {
                    return palindrome % 1337;
                }
            }
        }

        return 0;
    }
};