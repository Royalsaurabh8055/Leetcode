class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid,
                         int stampHeight,
                         int stampWidth) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        // Prefix sum of blocked cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] =
                    grid[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));

        // Find all valid stamp placements
        for (int r = 0; r + stampHeight - 1 < m; r++) {
            for (int c = 0; c + stampWidth - 1 < n; c++) {

                int r2 = r + stampHeight - 1;
                int c2 = c + stampWidth - 1;

                if (getSum(r, c, r2, c2) == 0) {

                    diff[r][c]++;

                    if (r2 + 1 < m)
                        diff[r2 + 1][c]--;

                    if (c2 + 1 < n)
                        diff[r][c2 + 1]--;

                    if (r2 + 1 < m && c2 + 1 < n)
                        diff[r2 + 1][c2 + 1]++;
                }
            }
        }

        // Build coverage matrix from difference array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i > 0)
                    diff[i][j] += diff[i - 1][j];

                if (j > 0)
                    diff[i][j] += diff[i][j - 1];

                if (i > 0 && j > 0)
                    diff[i][j] -= diff[i - 1][j - 1];
            }
        }

        // Every empty cell must be covered
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && diff[i][j] == 0)
                    return false;
            }
        }

        return true;
    }
};