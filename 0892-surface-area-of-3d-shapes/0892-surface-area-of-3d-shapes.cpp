class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int h = grid[i][j];

                if (h == 0)
                    continue;

                // Top + Bottom
                ans += 2;

                // Four sides
                ans += 4 * h;

                // Compare with upper neighbor
                if (i > 0) {
                    ans -= 2 * min(h, grid[i - 1][j]);
                }

                // Compare with left neighbor
                if (j > 0) {
                    ans -= 2 * min(h, grid[i][j - 1]);
                }
            }
        }

        return ans;
    }
};