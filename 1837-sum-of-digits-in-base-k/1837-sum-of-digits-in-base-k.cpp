class Solution {
public:
    int sumBase(int n, int k) {

        int ans = 0;

        while (n > 0) {

            // Get last digit in base k
            ans += n % k;

            // Remove last digit
            n /= k;
        }

        return ans;
    }
};