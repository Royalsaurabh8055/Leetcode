class Solution {
public:
    int numberOfCombinations(string num) {

        const int MOD = 1e9 + 7;
        int n = num.size();

        if (num[0] == '0')
            return 0;

        // lcp[i][j] = number of equal characters
        // starting from num[i] and num[j]
        vector<vector<int>> lcp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (num[i] == num[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }

        // dp[i][len]:
        // number of ways to split first i characters
        // where last number has length len
        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        // prefix[i][len]:
        // dp[i][1] + dp[i][2] + ... + dp[i][len]
        vector<vector<int>> prefix(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for (int i = 1; i <= n; i++) {

            for (int len = 1; len <= i; len++) {

                int start = i - len;

                // Leading zero not allowed
                if (num[start] == '0') {
                    prefix[i][len] = prefix[i][len - 1];
                    continue;
                }

                long long ways = 0;

                // First number
                if (start == 0) {
                    ways = 1;
                }
                else {

                    // Previous number shorter than current
                    int maxShorter = min(len - 1, start);

                    ways = prefix[start][maxShorter];

                    // Previous number has same length
                    if (start >= len) {

                        int prevStart = start - len;

                        int common =
                            lcp[prevStart][start];

                        bool valid = false;

                        if (common >= len) {
                            valid = true;
                        }
                        else if (
                            num[prevStart + common] <
                            num[start + common]
                        ) {
                            valid = true;
                        }

                        if (valid) {
                            ways += dp[start][len];
                        }
                    }
                }

                dp[i][len] = ways % MOD;

                prefix[i][len] =
                    (prefix[i][len - 1] + dp[i][len]) % MOD;
            }
        }

        return prefix[n][n];
    }
};