class Solution {
public:
    int numWays(string s) {
        long long MOD = 1000000007;

        int totalOnes = 0;

        for (char ch : s) {
            if (ch == '1')
                totalOnes++;
        }

        // Cannot divide the 1s equally among 3 parts
        if (totalOnes % 3 != 0)
            return 0;

        // If there are no 1s
        if (totalOnes == 0) {
            int n = s.length();

            // Choose 2 cuts from n-1 positions
            return (long long)(n - 1) * (n - 2) / 2 % MOD;
        }

        int each = totalOnes / 3;

        long long firstGap = 0;
        long long secondGap = 0;

        int ones = 0;

        // Count zeros after 1st group
        for (char ch : s) {
            if (ch == '1') {
                ones++;

                if (ones == each) {
                    firstGap = 1;
                }
                else if (ones == each + 1) {
                    break;
                }
            }
            else if (ones == each) {
                firstGap++;
            }
        }

        ones = 0;

        // Count zeros after 2nd group
        for (char ch : s) {
            if (ch == '1') {
                ones++;

                if (ones == 2 * each) {
                    secondGap = 1;
                }
                else if (ones == 2 * each + 1) {
                    break;
                }
            }
            else if (ones == 2 * each) {
                secondGap++;
            }
        }

        return (firstGap * secondGap) % MOD;
    }
};