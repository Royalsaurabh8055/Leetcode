class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {

        int n = grid.size();

        int xy = 0; // Top view
        int yz = 0; // Side view
        int zx = 0; // Front view

        for (int i = 0; i < n; i++) {

            int rowMax = 0;
            int colMax = 0;

            for (int j = 0; j < n; j++) {

                // Top view
                if (grid[i][j] > 0) {
                    xy++;
                }

                // Maximum height in current row
                rowMax = max(rowMax, grid[i][j]);

                // Maximum height in current column
                colMax = max(colMax, grid[j][i]);
            }

            yz += rowMax;
            zx += colMax;
        }

        return xy + yz + zx;
    }
};