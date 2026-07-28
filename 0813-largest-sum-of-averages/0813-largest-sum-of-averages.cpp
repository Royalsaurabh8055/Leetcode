class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix sum
        vector<double> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // dp[i][groups] = maximum score using
        // first i elements divided into 'groups' groups
        vector<vector<double>> dp(n + 1,
                                  vector<double>(k + 1, 0));

        // Base case: only one group
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }

        // Number of groups
        for (int groups = 2; groups <= k; groups++) {

            // Number of elements being considered
            for (int i = groups; i <= n; i++) {

                // Last group starts from j
                for (int j = groups - 1; j < i; j++) {

                    double average =
                        (prefix[i] - prefix[j]) / (i - j);

                    dp[i][groups] =
                        max(dp[i][groups],
                            dp[j][groups - 1] + average);
                }
            }
        }

        return dp[n][k];
    }
};