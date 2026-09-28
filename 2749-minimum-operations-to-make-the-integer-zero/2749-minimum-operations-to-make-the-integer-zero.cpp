class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for (long long k = 1; k <= 60; k++) {

            long long x = (long long)num1 - k * num2;

            // We need to represent x as a sum of k powers of 2.
            if (x < k)
                continue;

            // Minimum number of powers of 2 needed = number of set bits
            int bits = __builtin_popcountll(x);

            // Maximum number of powers of 2 using k terms is k
            // because we can split a power into two smaller powers.
            if (bits <= k)
                return k;
        }

        return -1;
    }
};