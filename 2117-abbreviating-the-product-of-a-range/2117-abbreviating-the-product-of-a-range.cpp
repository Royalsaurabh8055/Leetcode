class Solution {
public:
    string abbreviateProduct(int left, int right) {

        int count2 = 0;
        int count5 = 0;

        // Count factors of 2 and 5
        for (int i = left; i <= right; i++) {

            int x = i;

            while (x % 2 == 0) {
                count2++;
                x /= 2;
            }

            x = i;

            while (x % 5 == 0) {
                count5++;
                x /= 5;
            }
        }

        // Number of trailing zeros
        int zeros = min(count2, count5);

        // We only need to remove equal number of 2s and 5s
        count2 = zeros;
        count5 = zeros;

        // Last digits
        long long suffix = 1;

        // First digits
        double prefix = 1.0;

        bool large = false;

        for (int i = left; i <= right; i++) {

            // -------------------------
            // Calculate last digits
            // -------------------------

            suffix *= i;

            while (count2 > 0 && suffix % 2 == 0) {
                suffix /= 2;
                count2--;
            }

            while (count5 > 0 && suffix % 5 == 0) {
                suffix /= 5;
                count5--;
            }

            // Keep only last 10 digits
            if (suffix >= 10000000000LL) {
                large = true;
                suffix %= 10000000000LL;
            }


            // -------------------------
            // Calculate first digits
            // -------------------------

            prefix *= i;

            while (prefix >= 100000) {
                prefix /= 10;
            }
        }

        // Product after removing zeros has <= 10 digits
        if (!large) {
            return to_string(suffix) + "e" + to_string(zeros);
        }

        // Product has more than 10 digits
        string pre = to_string((long long)prefix);

        string suf = to_string(suffix % 100000);

        // Last 5 digits must contain leading zeros
        while (suf.length() < 5) {
            suf = "0" + suf;
        }

        return pre + "..." + suf + "e" + to_string(zeros);
    }
};