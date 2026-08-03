class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[201][201][2];

    int solve(int zero, int one, int last, int limit) {

        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][last] != -1)
            return dp[zero][one][last];

        long long ans = 0;

        if (last == 0) {

            // Last placed was 0, now place 1's
            for (int k = 1; k <= min(limit, one); k++) {
                ans = (ans + solve(zero, one - k, 1, limit)) % MOD;
            }

        } else {

            // Last placed was 1, now place 0's
            for (int k = 1; k <= min(limit, zero); k++) {
                ans = (ans + solve(zero - k, one, 0, limit)) % MOD;
            }
        }

        return dp[zero][one][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        // Start with 0's
        for (int k = 1; k <= min(limit, zero); k++) {
            ans = (ans + solve(zero - k, one, 0, limit)) % MOD;
        }

        // Start with 1's
        for (int k = 1; k <= min(limit, one); k++) {
            ans = (ans + solve(zero, one - k, 1, limit)) % MOD;
        }

        return ans;
    }
};