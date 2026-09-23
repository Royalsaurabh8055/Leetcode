class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);

        // Count 1s in every row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int onesRow = rowOnes[i];
                int onesCol = colOnes[j];

                int zerosRow = n - onesRow;
                int zerosCol = m - onesCol;

                diff[i][j] =
                    onesRow + onesCol - zerosRow - zerosCol;
            }
        }

        return diff;
    }
};