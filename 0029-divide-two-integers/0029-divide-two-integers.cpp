class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        // Try powers of 2 from large to small
        for (int i = 31; i >= 0; i--) {

            if ((b << i) <= a) {
                a -= (b << i);
                ans += (1LL << i);
            }
        }

        // Determine sign
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};