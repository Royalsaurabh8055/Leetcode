class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        // isPal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> isPal(
            n, vector<bool>(n, false)
        );

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || isPal[i + 1][j - 1])) {

                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            // If s[0...i] itself is palindrome
            if (isPal[0][i]) {
                dp[i] = 0;
                continue;
            }

            // Try every possible last palindrome
            dp[i] = i;  // worst case: cut every character

            for (int j = 1; j <= i; j++) {

                if (isPal[j][i]) {

                    dp[i] = min(
                        dp[i],
                        dp[j - 1] + 1
                    );
                }
            }
        }

        return dp[n - 1];
    }
};