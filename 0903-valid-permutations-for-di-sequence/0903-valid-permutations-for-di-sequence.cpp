class Solution {
public:
    int numPermsDISequence(string s) {

        int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> dp(n + 1, 1);

        for (int i = 0; i < n; i++) {

            vector<int> next(n + 1, 0);

            if (s[i] == 'I') {

                long long sum = 0;

                for (int j = 0; j < n - i; j++) {

                    sum = (sum + dp[j]) % MOD;

                    next[j] = sum;
                }
            }
            else {

                long long sum = 0;

                for (int j = n - i - 1; j >= 0; j--) {

                    sum = (sum + dp[j + 1]) % MOD;

                    next[j] = sum;
                }
            }

            dp = next;
        }

        return dp[0];
    }
};