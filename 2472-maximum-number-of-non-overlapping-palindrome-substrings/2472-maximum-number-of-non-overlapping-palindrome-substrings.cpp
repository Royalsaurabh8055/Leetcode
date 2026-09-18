class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // isPal[i][j] = s[i...j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Length 1
        for(int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        // Length 2 and more
        for(int len = 2; len <= n; len++) {

            for(int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if(s[i] == s[j]) {

                    if(len == 2)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = maximum palindromes in s[0...i-1]
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {

            // Don't use character i-1
            dp[i] = dp[i - 1];

            // Try palindrome ending at i-1
            for(int start = 0; start <= i - k; start++) {

                if(isPal[start][i - 1]) {

                    dp[i] = max(
                        dp[i],
                        dp[start] + 1
                    );
                }
            }
        }

        return dp[n];
    }
};