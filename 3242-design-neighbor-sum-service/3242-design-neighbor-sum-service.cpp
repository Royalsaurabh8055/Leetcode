class NeighborSum {
public:
    vector<vector<int>> grid;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
    }

    int adjacentSum(int value) {

        int row = 0, col = 0;

        // Find value position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == value) {
                    row = i;
                    col = j;
                }
            }
        }

        int sum = 0;

        // Up
        if (row - 1 >= 0)
            sum += grid[row - 1][col];

        // Down
        if (row + 1 < n)
            sum += grid[row + 1][col];

        // Left
        if (col - 1 >= 0)
            sum += grid[row][col - 1];

        // Right
        if (col + 1 < n)
            sum += grid[row][col + 1];

        return sum;
    }

    int diagonalSum(int value) {

        int row = 0, col = 0;

        // Find value position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == value) {
                    row = i;
                    col = j;
                }
            }
        }

        int sum = 0;

        // Top-left
        if (row - 1 >= 0 && col - 1 >= 0)
            sum += grid[row - 1][col - 1];

        // Top-right
        if (row - 1 >= 0 && col + 1 < n)
            sum += grid[row - 1][col + 1];

        // Bottom-left
        if (row + 1 < n && col - 1 >= 0)
            sum += grid[row + 1][col - 1];

        // Bottom-right
        if (row + 1 < n && col + 1 < n)
            sum += grid[row + 1][col + 1];

        return sum;
    }
};