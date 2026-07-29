class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // waste[i][j] = wasted space if nums[i...j]
        // uses one fixed size
        vector<vector<int>> waste(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {

            int maxValue = 0;

            for (int j = i; j < n; j++) {

                maxValue = max(maxValue, nums[j]);

                int totalSpace = maxValue * (j - i + 1);

                int usedSpace =
                    prefix[j + 1] - prefix[i];

                waste[i][j] =
                    totalSpace - usedSpace;
            }
        }

        const int INF = 1e9;

        // dp[i][g] = minimum waste for first i elements
        // using g groups
        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 2, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int groups = 1;
                 groups <= k + 1;
                 groups++) {

                for (int j = 0; j < i; j++) {

                    if (dp[j][groups - 1] == INF)
                        continue;

                    dp[i][groups] =
                        min(
                            dp[i][groups],
                            dp[j][groups - 1]
                            + waste[j][i - 1]
                        );
                }
            }
        }

        return dp[n][k + 1];
    }
};