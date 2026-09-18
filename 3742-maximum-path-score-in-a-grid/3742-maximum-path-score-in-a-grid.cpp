class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][cost] = maximum score
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        // Starting cell is always 0
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int cost = 0; cost <= k; cost++) {

                    if (dp[i][j][cost] == -1)
                        continue;

                    // Move Down
                    if (i + 1 < m) {
                        int newCost = cost + (grid[i + 1][j] > 0);

                        if (newCost <= k) {
                            dp[i + 1][j][newCost] =
                                max(dp[i + 1][j][newCost],
                                    dp[i][j][cost] + grid[i + 1][j]);
                        }
                    }

                    // Move Right
                    if (j + 1 < n) {
                        int newCost = cost + (grid[i][j + 1] > 0);

                        if (newCost <= k) {
                            dp[i][j + 1][newCost] =
                                max(dp[i][j + 1][newCost],
                                    dp[i][j][cost] + grid[i][j + 1]);
                        }
                    }
                }
            }
        }

        int ans = -1;

        for (int cost = 0; cost <= k; cost++) {
            ans = max(ans, dp[m - 1][n - 1][cost]);
        }

        return ans;
    }
};