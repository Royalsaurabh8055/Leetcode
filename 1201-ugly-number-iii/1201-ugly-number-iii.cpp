class Solution {
public:

    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countUgly(long long num,
                        long long a,
                        long long b,
                        long long c) {

        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        return num / a
             + num / b
             + num / c
             - num / ab
             - num / ac
             - num / bc
             + num / abc;
    }

    int nthUglyNumber(int n, int a, int b, int c) {

        long long low = 1;
        long long high = 2000000000;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long count = countUgly(mid, a, b, c);

            if (count >= n) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};