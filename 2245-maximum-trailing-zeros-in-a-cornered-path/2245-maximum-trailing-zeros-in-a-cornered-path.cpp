class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Factors of 2 and 5 in each cell
        vector<vector<int>> two(m, vector<int>(n));
        vector<vector<int>> five(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int x = grid[i][j];

                while (x % 2 == 0) {
                    two[i][j]++;
                    x /= 2;
                }

                while (x % 5 == 0) {
                    five[i][j]++;
                    x /= 5;
                }
            }
        }

        // Row prefix sums
        vector<vector<int>> row2(m, vector<int>(n + 1));
        vector<vector<int>> row5(m, vector<int>(n + 1));

        // Column prefix sums
        vector<vector<int>> col2(m + 1, vector<int>(n));
        vector<vector<int>> col5(m + 1, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                row2[i][j + 1] = row2[i][j] + two[i][j];
                row5[i][j + 1] = row5[i][j] + five[i][j];

                col2[i + 1][j] = col2[i][j] + two[i][j];
                col5[i + 1][j] = col5[i][j] + five[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // LEFT including current
                int left2 = row2[i][j + 1];
                int left5 = row5[i][j + 1];

                // RIGHT including current
                int right2 = row2[i][n] - row2[i][j];
                int right5 = row5[i][n] - row5[i][j];

                // UP including current
                int up2 = col2[i + 1][j];
                int up5 = col5[i + 1][j];

                // DOWN including current
                int down2 = col2[m][j] - col2[i][j];
                int down5 = col5[m][j] - col5[i][j];

                // LEFT + UP
                ans = max(ans,
                    min(left2 + up2 - two[i][j],
                        left5 + up5 - five[i][j]));

                // LEFT + DOWN
                ans = max(ans,
                    min(left2 + down2 - two[i][j],
                        left5 + down5 - five[i][j]));

                // RIGHT + UP
                ans = max(ans,
                    min(right2 + up2 - two[i][j],
                        right5 + up5 - five[i][j]));

                // RIGHT + DOWN
                ans = max(ans,
                    min(right2 + down2 - two[i][j],
                        right5 + down5 - five[i][j]));
            }
        }

        return ans;
    }
};