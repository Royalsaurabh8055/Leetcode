class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        // dp[k][r1][r2]
        // k  = number of steps taken by both
        // r1 = row of person 1
        // r2 = row of person 2
        vector<vector<vector<int>>> dp(
            2 * n - 1,
            vector<vector<int>>(n, vector<int>(n, -1))
        );

        // Both start at (0,0)
        dp[0][0][0] = grid[0][0];

        for (int k = 1; k < 2 * n - 1; k++) {

            for (int r1 = 0; r1 < n; r1++) {
                for (int r2 = 0; r2 < n; r2++) {

                    int c1 = k - r1;
                    int c2 = k - r2;

                    // Out of bounds
                    if (c1 < 0 || c1 >= n ||
                        c2 < 0 || c2 >= n)
                        continue;

                    // Thorn
                    if (grid[r1][c1] == -1 ||
                        grid[r2][c2] == -1)
                        continue;

                    int best = -1;

                    // Previous positions
                    // Person 1: up or left
                    // Person 2: up or left

                    if (r1 > 0 && r2 > 0)
                        best = max(best, dp[k-1][r1-1][r2-1]);

                    if (r1 > 0)
                        best = max(best, dp[k-1][r1-1][r2]);

                    if (r2 > 0)
                        best = max(best, dp[k-1][r1][r2-1]);

                    best = max(best, dp[k-1][r1][r2]);

                    if (best == -1)
                        continue;

                    // Collect cherries
                    int cherries = grid[r1][c1];

                    // If both are on different cells,
                    // count both cherries
                    if (r1 != r2)
                        cherries += grid[r2][c2];

                    dp[k][r1][r2] = best + cherries;
                }
            }
        }

        return max(0, dp[2*n-2][n-1][n-1]);
    }
};